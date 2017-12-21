#include "BattleNetProxy.h"
#include "BattleManagerModuleDefine.h"
#include "CommDef.h"
#include "BattleUserManager.h"

MP_SINGLETON_IMPLEMENT(BattleNetProxy);

BattleNetProxy::BattleNetProxy()
	: NetProxy(10), m_Mgrs(eBattleManagerModule, eBattleMgr_End)
{
}

BattleNetProxy::~BattleNetProxy()
{
}

bool BattleNetProxy::InitServerCfg(const std::string& filename)
{
	AddTCPServerModule(MP_ST_GAME, 3000, "127.0.0.1", 16130, 1);
	AddRUDPServerModule(MP_RUDP_CLIENT, 2048, "127.0.0.1", 17002);

	return true;
}

void BattleNetProxy::LogicStart()
{
	if (!m_Mgrs.Awake())
	{
		ImmediatelyFinal("Awake Failed!");
	}
}
void BattleNetProxy::LogicFinal()
{
	m_Mgrs.ShutDown();
}

void BattleNetProxy::LogicRun()
{
	m_Mgrs.Execute();
	if (0)
	{
		Final("");
	}
}

void BattleNetProxy::OnClientConnected(const uint8_t nType, const MPSOCK nSockIndex)
{
	switch (nType)
	{
	case MP_ST_GAME:
	break;
	case MP_ST_CENTER:
	{
	}
	break;
	case MP_RUDP_CLIENT:
	{
		//temp client
		auto pBattleUserMgr = g_pBattleNetProxy->GetModule<BattleUserManager>(eBattleMgr_BattleUser);
		pBattleUserMgr->AddBattleUser(nSockIndex);
		
		MP_INFO("New RUDP Client [%llu] Connected!",nSockIndex);
	}
	default:
		break;
	}
}

void BattleNetProxy::OnClientDisconnect(const uint8_t nType, const MPSOCK nSockIndex)
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
		auto pGameServerMgr = GetModule<GameServerManager>(eBattleMgr_GameServer);
		pGameServerMgr->AddGameServer(nSockIndex, pNetObject->GetIP().c_str(), pNetObject->GetPort());
	}
	break;
	case MP_ST_GATE:
	{
		auto pGateServerMgr = GetModule<GateServerManager>(eBattleMgr_GateServer);
		pGateServerMgr->AddGateServer(nSockIndex, pNetObject->GetIP().c_str(), pNetObject->GetPort());
	}*/
	break;
	case MP_ST_CENTER:
	{
	}
	break;
	case MP_RUDP_CLIENT:
	{
		auto pBattleUserMgr = g_pBattleNetProxy->GetModule<BattleUserManager>(eBattleMgr_BattleUser);
		pBattleUserMgr->DelBattleUser(nSockIndex);
		MP_INFO("RUDP Client [%llu] DisConnected!",nSockIndex);
	}
	break;
	default:
		break;
	}
}

const MPGUID BattleNetProxy::GetGUIDBySock(const uint8_t nType, const MPSOCK nSockIndex)const
{
	return 0;
}