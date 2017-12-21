#include "MatchNetProxy.h"
#include "MatchManagerModuleDefine.h"
#include "CommDef.h"

MP_SINGLETON_IMPLEMENT(MatchNetProxy);

MatchNetProxy::MatchNetProxy()
	: NetProxy(10), m_Mgrs(eMatchManagerModule, eMatchMgr_End)
{
}

MatchNetProxy::~MatchNetProxy()
{
}

bool MatchNetProxy::InitServerCfg(const std::string& filename)
{
	AddTCPClientModule(MP_ST_CENTER, "127.0.0.1", 12345);
	AddTCPServerModule(MP_ST_SUPER, 3000, "127.0.0.1", 16131);

	return true;
}

void MatchNetProxy::LogicStart()
{
	if (!m_Mgrs.Awake())
	{
		ImmediatelyFinal("Awake Failed!");
	}
}
void MatchNetProxy::LogicFinal()
{
	m_Mgrs.ShutDown();
}

void MatchNetProxy::LogicRun()
{
	m_Mgrs.Execute();
	if (0)
	{
		Final("");
	}
}

void MatchNetProxy::OnClientConnected(const uint8_t nType, const MPSOCK nSockIndex)
{
	switch (nType)
	{
	case MP_ST_GAME:
	/*{
		auto pGameServerMgr = GetModule<GameServerManager>(eMatchMgr_GameServer);
		pGameServerMgr->DelGameServer(nSockIndex);
		MP_INFO("GameServer Disconnected![%lld]", nSockIndex);
	}
	break;
	case MP_ST_GATE:
	{
		auto pGateServerMgr = GetModule<GateServerManager>(eMatchMgr_GateServer);
		pGateServerMgr->DelGateServer(nSockIndex);
		MP_INFO("GateServer Disconnected![%lld]", nSockIndex);
	}*/
	break;
	case MP_ST_CENTER:
	{
	}
	break;
	case MP_RUDP_CLIENT:
	{
		//temp client
		
		MP_INFO("New RUDP Client [%llu] Connected!",nSockIndex);
	}
	default:
		break;
	}
}

void MatchNetProxy::OnClientDisconnect(const uint8_t nType, const MPSOCK nSockIndex)
{
	auto pNetModule = GetNetModule(nType);
	auto pNetObject = pNetModule->GetNetObject(nSockIndex);
	if (pNetObject == nullptr)
	{
		return;
	}

	switch (nType)
	{
	case MP_ST_GAME:
	/*{
		auto pGameServerMgr = GetModule<GameServerManager>(eMatchMgr_GameServer);
		pGameServerMgr->AddGameServer(nSockIndex, pNetObject->GetIP().c_str(), pNetObject->GetPort());
	}
	break;
	case MP_ST_GATE:
	{
		auto pGateServerMgr = GetModule<GateServerManager>(eMatchMgr_GateServer);
		pGateServerMgr->AddGateServer(nSockIndex, pNetObject->GetIP().c_str(), pNetObject->GetPort());
	}*/
	break;
	case MP_ST_CENTER:
	{
	}
	break;
	case MP_RUDP_CLIENT:
	{
		MP_INFO("RUDP Client [%llu] DisConnected!",nSockIndex);
	}
	break;
	default:
		break;
	}
}

const MPGUID MatchNetProxy::GetGUIDBySock(const uint8_t nType, const MPSOCK nSockIndex)const
{
	return 0;
}