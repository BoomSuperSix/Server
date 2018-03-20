#pragma once

#include "MPNet.h"
#include "evhttp.h"


namespace meplay
{
	class MPNetObject;
	class MPHTTPServer;
	class MPHTTPServer : public MPNet
	{
	public:
		template<typename BaseType>
		explicit MPHTTPServer(
			const std::string& sServerName,
			uint8_t nServerType,
			BaseType* pBaseType,
			bool (BaseType::*handleMsg)(const uint8_t,const std::string&,const std::string&,std::string&)
		) 
		{
			m_MsgCB = std::bind(
				handleMsg, 
				pBaseType, 
				std::placeholders::_1, 
				std::placeholders::_2, 
				std::placeholders::_3,
				std::placeholders::_4
			);

			SetNetType(MP_NET_TYPE_HTTP_SERVER);
			SetServerType(nServerType);
		};
		//MPHTTPServer(, uint8_t nServerType, int nPort, uint8_t nThreadCount);
		virtual ~MPHTTPServer();
	public:
		virtual bool Execute()override;

		virtual int InitializationAsClient(const char* strIP, const unsigned short nPort, bool bAutoReconnect, const uint32_t milliseconds)override;

		virtual int InitializationAsServer(const char* strIP, const unsigned int nMaxClient, const unsigned short nPort, const int nThreadCount = 0)override;

		virtual bool Final()override;

	public:
		static MPHTTPServer* GetHttpServer(int nPort);
	public:
		std::function<bool(const uint8_t, const std::string&,const std::string&,std::string&)> m_MsgCB;
	private:
		int m_nPort;
		int m_nThreadCount;
		const std::string m_sServiceName;

		event_base* m_pEventBase;
		evhttp*		m_pHttp;

		std::unordered_map<MPSOCK, MPNetObjectPtr> m_mNetObjects;

		//port<-->http
		static std::map<uint16_t, MPHTTPServer*> m_mHttpRequest;
	};

}