#include "MPHttpServer.h"
#include "MPNetObject.h"
#include "MPLogger.h"
#include "http_server.h"

using namespace meplay;
std::map<uint16_t, MPHTTPServer*> MPHTTPServer::m_mHttpRequest;

MPHTTPServer::~MPHTTPServer()
{
}

bool MPHTTPServer::Execute()
{
	event_base_loop(m_pEventBase, EVLOOP_NONBLOCK);
	if (0)
	{
		Final();
	}
	return true;
}

int MPHTTPServer::InitializationAsClient(const char* strIP, const unsigned short nPort, bool bAutoReconnect, const uint32_t milliseconds)
{
	return -1;
}

void HttpCallback(struct evhttp_request* request, void* arg)
{
	MP_INFO("request url : %s.", request->uri);
	auto pHttpServer = MPHTTPServer::GetHttpServer(*(int*)arg);
	if (pHttpServer == nullptr)
	{
		return;
	}

	std::string sURI = request->uri;
	auto sPath = sURI.substr(0,sURI.find_first_of("?", 0));
	std::string sRequest("");
	switch (request->type)
	{
	case EVHTTP_REQ_GET:
	{
		sRequest = sURI.substr(sURI.find_first_of("?", 0) + 1, sURI.size());
	}
	break;
	case EVHTTP_REQ_POST:
	{
		auto buf = evhttp_request_get_input_buffer(request);
		while (evbuffer_get_length(buf))
		{
			char cbuf[1024];
			int count = evbuffer_remove(buf, cbuf, sizeof(cbuf));
			sRequest.append(cbuf, count);
		}
	}
	break;
	default:
		break;
	}
	std::string sResponse;
	struct evbuffer* evbuf = evbuffer_new();
	if (evbuf == nullptr)
	{
		MP_ERROR("Create evbuffer failed!\n");
		return;
	}
	if (pHttpServer->m_MsgCB(pHttpServer->GetServerType(), sPath, sRequest, sResponse))
	{
		evbuffer_add_printf(evbuf, "%s", sResponse.c_str());
		evhttp_send_reply(request, HTTP_OK, "OK", evbuf);
	}
	else
	{
		//evbuffer_add_printf(evbuf, "%s", sResponse.c_str());
		evhttp_send_reply(request, HTTP_NOTFOUND, "Fuxk U!", evbuf);
	}
	evbuffer_free(evbuf);
}

int MPHTTPServer::InitializationAsServer(const char* strIP, const unsigned int nMaxClient, const unsigned short nPort, const int nThreadCount)
{
	m_nPort = nPort;
	m_nThreadCount = nThreadCount;
#ifdef WIN_SYSTEM
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		MP_ERROR("WSAStartup failed with error: %d\n", err);
		return -1;
	}
#endif
	m_pEventBase = event_base_new();
	if (m_pEventBase == nullptr)
	{
		MP_ERROR("Create event base failed!");
		return -1;
	}

	m_pHttp = evhttp_new(m_pEventBase);
	if (m_pHttp == nullptr)
	{
		MP_ERROR("Create evhttp failed!");
		return -1;
	}
	int ret = evhttp_bind_socket(m_pHttp, strIP, nPort);
	if (ret != 0)
	{
		MP_ERROR("Bind evhttp socket failed!");
		return -1;
	}

	//evhttp_set_cb(m_pHttp, "test", HttpCallback, NULL);
	evhttp_set_gencb(m_pHttp, HttpCallback, &m_nPort);

	m_mHttpRequest.emplace(m_nPort, this);
	return 0;
}

bool MPHTTPServer::Final()
{
	event_base_loopbreak(m_pEventBase);
	evhttp_free(m_pHttp);
	event_base_free(m_pEventBase);

#ifdef WIN_SYSTEM
	WSACleanup();
#endif
	return true;
}

MPHTTPServer* MPHTTPServer::GetHttpServer(int nPort)
{
	auto it = m_mHttpRequest.find(nPort);
	if (it == m_mHttpRequest.end())
	{
		return nullptr;
	}
	return it->second;
}