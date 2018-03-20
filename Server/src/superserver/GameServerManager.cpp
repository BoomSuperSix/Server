#include "GameServerManager.h"
#include "SuperTimeManager.h"

GameServerManager::GameServerManager()
	: ManagerModule(eSuperMgr_GameServer)
{
}

GameServerManager::~GameServerManager()
{
}
bool GameServerManager::Awake()
{
	REGISTER_HTTP("/echo",this, GameServerManager::TestHTTPCB);
	return true;
}

bool GameServerManager::AfterAwake()
{
	return true;
}

bool GameServerManager::Execute()
{
	return true;
}

bool GameServerManager::BeforeShutDown()
{
	return true;
}

bool GameServerManager::ShutDown()
{
	return true;
}

void GameServerManager::AddGameServer(uint64_t nSockIndex, const char* ip, int nPort)
{
	auto pGameServer = std::make_shared<GameServer>(nSockIndex, ip, nPort);
	if (pGameServer == nullptr)
	{
		return;
	}

	if (!m_mGameServers.emplace(nSockIndex, pGameServer).second)
	{
		MP_ERROR("Same Game Server!");
	}
}

void GameServerManager::DelGameServer(uint64_t nSockIndex)
{
	m_mGameServers.erase(nSockIndex);
}

void GameServerManager::TestHTTPCB(const std::string& sParam, std::string& sResponse)
{
	sResponse.append("{\"aa\":1,\"b\"=\"afadfa\"}");
	sResponse.append(std::to_string(SUPER_CUR_TIME.CurrentSec()));
	MP_INFO("This is cb.%s,%s.", sParam.c_str(), sResponse.c_str());
}