#pragma once
#include "BattleCommDef.h"
#include "BattleUser.h"
#include "MPMemoryPool.h"

class BattleUserManager final : public ManagerModule
{
public:
	BattleUserManager();
	~BattleUserManager();
public:
	virtual bool Awake()override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutDown()override;
	virtual bool ShutDown()override;
public:
	void AddBattleUser(uint64_t nSockIndex);
	void DelBattleUser(uint64_t nSockIndex);

	void OnBattleUserLogin(const std::string& sData, const uint64_t nSockIndex);

private:
	MPMemoryPool<BattleUser> m_BattleUserPool;
	std::unordered_map<uint64_t, BattleUserPtr> m_mBattleUsers;

	std::unordered_map<uint64_t,meplay::MPTime> m_mTempBattleUsers;
};

BATTLE_MANAGER_MODULE_REG(eBattleMgr_BattleUser, BattleUserManager);
