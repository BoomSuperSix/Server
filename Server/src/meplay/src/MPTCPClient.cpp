#include "MPTCPClient.h"
#include "tcp_client.h"
#include "event_loop.h"
#include "MPThread.h"
#include "tcp_conn.h"
#include "buffer.h"
#include "MPNetObject.h"

using namespace meplay;
using namespace evpp;

MPTCPClient::~MPTCPClient()
{
}

bool MPTCPClient::Execute()
{
	MPThread::ThreadStart();
	if (0)
	{
		Final();
	}

	auto now = meplay::MPTime();
	//check reconnect
	for (auto& pData : m_vConnectData)
	{
		if (!pData->m_bAutoConnect)
		{
			continue;
		}
		if (pData->m_nStatus != TCP_CLIENT_DISCONNECTED)
		{
			continue;
		}

		if (!pData->m_tDisconnectTime.IsMTimeOut(pData->m_nIntervalMSec))
		{
			continue;
		}

		pData->m_nStatus = TCP_CLIENT_RECONNECT;
		pData->m_pClient->Connect();
		MP_DEBUG("Reconnect To [%s]!",pData->m_pClient->remote_addr().c_str());
	}
	
	return true;
}

void MPTCPClient::Run()
{
	MP_DEBUG("MPTCPClient Start Run!");
	m_pEventLoop->Run();
	MP_DEBUG("MPTCPClient End Run!");
	while (!IsThreadFinal())
	{
	}
	MP_DEBUG("MPTCPClient Run Over!");
}

void MPTCPClient::connectCB(const std::shared_ptr<evpp::TCPConn>& pConn, TCPConnectData* pData)
{
	if (pConn->IsConnected())
	{
		//new connect
		auto pNetObj = std::make_shared<MPTCPObject>(pConn);
		AddNetObject(pConn->fd(), pNetObj);
		m_ConnectCB(GetServerType(), pConn->fd());
		pData->m_nStatus = TCP_CLIENT_CONNECTED;
		MP_DEBUG("Connect To [%s] Success!",pData->m_pClient->remote_addr().c_str());
	}
	else
	{
		//disconnect
		if (GetNetObject(pConn->fd()) != nullptr)
		{
			m_DisConnectCB(GetServerType(), pConn->fd());
			DelNetObject(pConn->fd());
		}
		pData->m_nStatus = TCP_CLIENT_DISCONNECTED;
		pData->m_tDisconnectTime = meplay::MPTime();

		cv.notify_all();
	}
}

void MPTCPClient::messageCB(const std::shared_ptr<evpp::TCPConn>& pConn, evpp::Buffer* pBuffer)
{
	auto pNetObj = GetNetObject(pConn->fd());
	if (pNetObj == nullptr)
	{
		return;
	}
	m_MsgCB(GetServerType(), pNetObj->GetRealFD(), pBuffer->data(), (uint32_t)pBuffer->length());
	pBuffer->Reset();
}

bool MPTCPClient::isAllDisConnected()
{
	for (auto& pData : m_vConnectData)
	{
		if (pData->m_nStatus != TCP_CLIENT_DISCONNECTED
			&& pData->m_nStatus != TCP_CLIENT_CONNECTING)
		{
			return false;
		}
	}
	return true;
}

int MPTCPClient::InitializationAsClient(const char* strIP, const unsigned short nPort, bool bAutoReconnect, const uint32_t milliseconds)
{
#ifdef WIN_SYSTEM
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		MP_ERROR("WSAStartup failed with error: %d\n", err);
	}
#endif
	if (m_pEventLoop == nullptr)
	{
		m_pEventLoop.reset(new EventLoop());
	}

	auto pData = new TCPConnectData();
	pData->m_pClient = std::make_shared<TCPClient>(m_pEventLoop.get(), std::string(strIP) + ":" + std::to_string(nPort), m_sServiceName);
	pData->m_bAutoConnect = bAutoReconnect;
	pData->m_pClient->set_auto_reconnect(false);
	pData->m_nIntervalMSec = milliseconds - 1000;
	pData->m_nStatus = TCP_CLIENT_CONNECTING;

	pData->m_pClient->SetConnectionCallback([&,pData](const std::shared_ptr<evpp::TCPConn>& pConn) { connectCB(pConn, pData); });
	pData->m_pClient->SetMessageCallback(std::bind(&MPTCPClient::messageCB, this, std::placeholders::_1, std::placeholders::_2));

	pData->m_pClient->Connect();
	MP_DEBUG("Try Connect To [%s]!", pData->m_pClient->remote_addr().c_str());

	m_vConnectData.emplace_back(pData);

	return 0;
}

int MPTCPClient::InitializationAsServer(const char* strIP, const unsigned int nMaxClient, const unsigned short nPort, const int nThreadCount)
{

	return -1;
}

bool MPTCPClient::Final()
{
	auto mNetObjs = GetAllNetObject();
	for (auto& ni : mNetObjs)
	{
		ni.second->Close();
		std::unique_lock<std::mutex> lck(mtx);
		cv.wait(lck);
	}

	for (auto& pData : m_vConnectData)
	{
		pData->m_pClient->Disconnect();
	}

	while(!isAllDisConnected())
	{
		MSleep(100);
		//std::unique_lock<std::mutex> lck(mtx);
		//cv.wait(lck);
	}

	if (!m_pEventLoop->IsStopped())
	{
		while (!m_pEventLoop->IsRunning())
		{
			this->MSleep(100);
		}

		m_pEventLoop->Stop();

		while (!m_pEventLoop->IsStopped())
		{
			this->MSleep(100);
		}
	}

	for (auto& pData : m_vConnectData)
	{
		delete pData;
		pData = nullptr;
	}
	m_vConnectData.clear();
	
	m_pEventLoop.reset();

	MPThread::ThreadFinal();

#ifdef WIN_SYSTEM
	WSACleanup();
#endif
	return true;
}
