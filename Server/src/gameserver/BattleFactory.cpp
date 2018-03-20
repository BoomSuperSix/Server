#include "BattleFactory.h"

BattleFactory::BattleFactory()
{
}

BattleFactory::~BattleFactory()
{
}

BattlePtr BattleFactory::CreateBattle(BATTLE_TYPE nType)
{
	switch (nType)
	{
	case eBattleType_PVE:
	{
		return m_mPVEPool.Get<BattlePVE>();
	}
	break;
	default:
		break;
	}
	return nullptr;
}