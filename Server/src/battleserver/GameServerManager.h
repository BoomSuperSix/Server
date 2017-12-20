#pragma once
#include "BattleCommDef.h"
#include "GameServer.h"

class GameServerManager final : public ManagerModule
{
public:
	GameServerManager();
	~GameServerManager();
public:
	virtual bool Awake()override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutDown()override;
	virtual bool ShutDown()override;
public:
	void AddGameServer(uint64_t nSockIndex, const char* ip, int nPort);
	void DelGameServer(uint64_t nSockIndex);
private:
	std::map<const uint64_t, GameServerPtr> m_mGameServers;
};

BATTLE_MANAGER_MODULE_REG(eBattleMgr_GameServer, GameServerManager);
