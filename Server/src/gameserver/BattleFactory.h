#pragma once

#include "MPMemoryPool.h"
#include "Battle.h"
#include "BattleCommDef.h"

class BattleFactory final
{
public:
	BattleFactory();
	~BattleFactory();
public:
	BattlePtr CreateBattle(BATTLE_TYPE nType);
private:
	MPMemoryPool<BattlePVE> m_mPVEPool;
};
