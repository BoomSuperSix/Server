#include "GameNetProxy.h"
#include "GameManagerModuleDefine.h"
#include "CommDef.h"
#include "GateServerManager.h"
#include "StatsServerManager.h"
#include "SuperServerManager.h"
#include "DBClientMgr.h"
#include "GameUserManager.h"
#include "Game2Super.pb.h"
#include "BattleManager.h"

MP_SINGLETON_IMPLEMENT(GameNetProxy);

GameNetProxy::GameNetProxy() 
	: NetProxy(100),m_Mgrs(eGameManagerModule,eGameMgr_End)
{
}

GameNetProxy::~GameNetProxy()
{
}

bool GameNetProxy::InitServerCfg(const std::string& filename)
{
	//server info
	m_nPlatformId = 1;
	m_nServerId = 1;

	//AddTCPClientModule(MP_ST_SUPER, "127.0.0.1", 16123);
	//AddTCPServerModule(MP_ST_GATE, 3000, "127.0.0.1", 16125,1);
	AddRUDPServerModule(MP_RUDP_CLIENT, 2048, "127.0.0.1", 17002);

	return true;
}

void GameNetProxy::LogicStart()
{
	if (!m_Mgrs.Awake())
	{
		ImmediatelyFinal("Mgr Awake Failed!");
	}

	g_pBattleMgr->ThreadStart();

}
void GameNetProxy::LogicFinal()
{
	g_pBattleMgr->ThreadFinal();

	m_Mgrs.ShutDown();
}

void GameNetProxy::LogicRun()
{
	m_Mgrs.Execute();

	if (0)
	{
		this->Final("");
	}
}

void GameNetProxy::OnClientDisconnect(const uint8_t nType, const MPSOCK nSockIndex)
{
	switch (nType)
	{
	case MP_ST_SUPER:
	{
		auto pSuperServerMgr = GetModule<SuperServerManager>(eGameMgr_SuperServer);
		pSuperServerMgr->DelSuperServer(nSockIndex);
		MP_INFO("SuperServer Disconnected![%lld]", nSockIndex);
	}
	break;
	case MP_ST_GATE:
	{
		auto pGateServerMgr = GetModule<GateServerManager>(eGameMgr_GateServer);
		pGateServerMgr->DelGateServer(nSockIndex);
		MP_INFO("GateServer Disconnected![%lld]", nSockIndex);

		auto pGameUserMgr = GetModule<GameUserManager>(eGameMgr_GameUser);
		pGameUserMgr->KickAllByGateSock(nSockIndex);
	}
	break;
	case MP_ST_CENTER:
	{
	}
	break;
	default:
		break;
	}
}

void GameNetProxy::OnClientConnected(const uint8_t nType, const MPSOCK nSockIndex)
{
	auto pNetModule = GetNetModule(nType);
	auto pNetObject = pNetModule->GetNetObject(nSockIndex);
	if (pNetObject == nullptr)
	{
		return;
	}

	switch (nType)
	{
	case MP_ST_SUPER:
	{
		auto pGameServerMgr = GetModule<SuperServerManager>(eGameMgr_SuperServer);
		pGameServerMgr->AddSuperServer(nSockIndex, pNetObject->GetIP().c_str(), pNetObject->GetPort());
	}
	break;
	case MP_ST_GATE:
	{
		auto pGateServerMgr = GetModule<GateServerManager>(eGameMgr_GateServer);
		pGateServerMgr->AddGateServer(nSockIndex, pNetObject->GetIP().c_str(), pNetObject->GetPort());
	}
	break;
	case MP_ST_CENTER:
	{
	}
	break;
	default:
		break;
	}
}


const MPGUID GameNetProxy::GetGUIDBySock(const uint8_t nType, const MPSOCK nSockIndex)const
{
	return 0;
}

//void GameNetProxy::SendGameMsgWrapper(
//	uint32_t nPlatfromId,
//	uint32_t nServerId,
//	uint8_t nServerType,
//	const uint16_t nMsgId,
//	google::protobuf::Message& msg
//)
//{
//	MPMsg::GameMsg_Wrapper outMsg;
//	outMsg.set_platfrom_id_from(m_nPlatformId);
//	outMsg.set_server_id_from(m_nServerId);
//	outMsg.set_server_type_from(MP_ST_GAME);
//	outMsg.set_platfrom_id_to(nPlatfromId);
//	outMsg.set_server_id_to(nServerId);
//	outMsg.set_server_type_to(nServerType);
//}
