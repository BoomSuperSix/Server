#pragma once
#include <unordered_map>

#include "MPSingleton.h"
#include "MPMemoryPool.h"
#include "MPThread.h"
#include "MPTime.h"
#include "BattleBase.h"
#include "BattleCommDef.h"
#include "BattleInfo.h"
#include "BattleFactory.h"

class BattleManager : public meplay::MPThread
{
	MP_SINGLETON_DECLARE(BattleManager);
public:
	virtual void Run()override;
public:
	//战斗帧
	void UpdateBattle();

	BATTLE_ID_TYPE AddBattle(const BattleInfo& bi);

	void DelBattle(BATTLE_ID_TYPE id);
private:
	//创建战斗唯一ID
	BATTLE_ID_TYPE createBattleId();

	void addBattle();
	void delBattle();
	void updateBattle();

private:
	BattleFactory m_BattleFactory;
	std::unordered_map<BATTLE_ID_TYPE, BattlePtr> m_mBattleMap;
	meplay::MPTime m_tLastTime;
	std::vector<std::pair<BATTLE_ID_TYPE,BattlePtr>> m_vAddCache;
	std::vector<BATTLE_ID_TYPE> m_vDelCache;
};

#define g_pBattleMgr BattleManager::GetInstance()