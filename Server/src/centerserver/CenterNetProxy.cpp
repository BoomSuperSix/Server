#include "CenterNetProxy.h"
#include "CenterManagerModuleDefine.h"
#include "CommDef.h"
#include "CenterCommDef.h"

MP_SINGLETON_IMPLEMENT(CenterNetProxy);

CenterNetProxy::CenterNetProxy() 
	: NetProxy(100),m_Mgrs(eCenterManagerModule,eCenterMgr_End)
{
}

CenterNetProxy::~CenterNetProxy()
{
}

bool CenterNetProxy::InitServerCfg(const std::string& filename)
{
	//AddTCPServerModule(MP_ST_GAME, 3000, "127.0.0.1", 16123, 1);
	//AddTCPServerModule(MP_ST_GATE, 3000, "127.0.0.1", 16124, 1);

	//AddReceiveCallBack();
	//AddTCPServerModule(MP_ST_CENTER, 3000, 16125);
	return true;
}

void CenterNetProxy::LogicStart()
{
	m_Mgrs.Awake();
}
void CenterNetProxy::LogicFinal()
{
	m_Mgrs.ShutDown();
}

void CenterNetProxy::LogicRun()
{
	m_Mgrs.Execute();
	if (0)
	{
		Final("");
	}
}

void CenterNetProxy::OnClientDisconnect(const uint8_t nType, const MPSOCK nSockIndex)
{
	switch (nType)
	{
	/*case MP_ST_GAME:
	{
		auto pGameServerMgr = GetModule<GameServerManager>(eCenterMgr_GameServer);
		pGameServerMgr->DelGameServer(nSockIndex);
		MP_INFO("GameServer Disconnected![%lld]", nSockIndex);
	}
	break;
	case MP_ST_GATE:
	{
		auto pGateServerMgr = GetModule<GateServerManager>(eCenterMgr_GateServer);
		pGateServerMgr->DelGateServer(nSockIndex);
		MP_INFO("GateServer Disconnected![%lld]",nSockIndex);
	}
	break;
	case MP_ST_CENTER:
	{
	}
	break;*/
	default:
		break;
	}
}

void CenterNetProxy::OnClientConnected(const uint8_t nType, const MPSOCK nSockIndex)
{
	auto pNetModule = GetNetModule(nType);
	auto pNetObject = pNetModule->GetNetObject(nSockIndex);
	if (pNetObject == nullptr)
	{
		return;
	}

	switch (nType)
	{
	//case MP_ST_GAME:
	//{
	//	auto pGameServerMgr = GetModule<GameServerManager>(eCenterMgr_GameServer);
	//	pGameServerMgr->AddGameServer(nSockIndex, pNetObject->GetIP().c_str(), pNetObject->GetPort());
	//}
	//break;
	//case MP_ST_GATE:
	//{
	//	auto pGateServerMgr = GetModule<GateServerManager>(eCenterMgr_GateServer);
	//	pGateServerMgr->AddGateServer(nSockIndex, pNetObject->GetIP().c_str(), pNetObject->GetPort());
	//}
	//break;
	//case MP_ST_CENTER:
	//{
	//}
	//break;
	default:
		break;
	}
}

const MPGUID CenterNetProxy::GetGUIDBySock(const uint8_t nType, const MPSOCK nSockIndex)const
{
	return 0;
}