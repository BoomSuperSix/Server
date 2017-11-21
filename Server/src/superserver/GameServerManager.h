#pragma once
#include "SuperCommDef.h"
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
	H_SUPER_MANAGER_REG(GameServerManager);

	std::map<const uint64_t, GameServerPtr> m_mGameServers;
};