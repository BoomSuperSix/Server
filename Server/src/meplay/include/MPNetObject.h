#pragma once
#include <memory>
#include <string>
#include <map>
#include <optional>
#ifdef WIN_SYSTEM
#include <WinSock2.h>
#else
#include <netinet/in.h>
#endif
#include "event2/bufferevent.h"
//#include "event2/http_struct.h"
#include "event2/buffer.h"
#include "evhttp.h"
#include "enet/enet.h"
#include "MPNetDefine.h"

namespace evpp {
	class TCPConn;
	class TCPClient;
}

namespace meplay {
	class MPNet;
	class MPNetObject
	{
	public:
		MPNetObject();
		virtual ~MPNetObject();
	public:
		MPSOCK GetRealFD()const;
		const std::string& GetIP()const;
		const int GetPort()const;
		
		virtual void Send(const char * data, uint32_t len) = 0;
		virtual void Close() = 0;
	protected:
		MPSOCK m_nFD;
		std::string m_sIP;
		int m_nPort;
	};
	typedef std::shared_ptr<MPNetObject> MPNetObjectPtr;

	class MPTCPObject : public MPNetObject
	{
	public:
		MPTCPObject(const std::shared_ptr<evpp::TCPConn>& pConn);
		virtual ~MPTCPObject();
	public:
		virtual void Send(const char * data, uint32_t len)override;
		virtual void Close()override;

		std::shared_ptr<evpp::TCPConn>& GetConn();
	private:
		std::shared_ptr<evpp::TCPConn> m_pConn;
	};

	class MPRUDPObject : public MPNetObject
	{
	public:
		MPRUDPObject(ENetPeer* pPeer);
		virtual ~MPRUDPObject();
	public:
		virtual void Send(const char * data, uint32_t len)override;
		virtual void Close()override;

		ENetPeer* GetENetPeer();
	private:
		uint32_t createRUDPFD();
	private:
		static uint32_t m_nSeed;
		ENetPeer* m_pPeer;
	};

	class MPHttpObject : public MPNetObject
	{
	public:
		MPHttpObject(struct evhttp_request* request);
		virtual ~MPHttpObject();
	public:
		virtual void Send(const char * data, uint32_t len)override;
		virtual void Close()override;
	public:
		void Post(const char * data,uint32_t len);
		void Get(const char * data,uint32_t len);
		const char * Path();
	private:
		uint32_t createHttpFD();
	private:
		struct evhttp_request* m_pRequest;
		static uint32_t m_nSeed;
	};
}

