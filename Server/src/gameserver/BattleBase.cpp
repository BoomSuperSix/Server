#include "BattleBase.h"

BattleBase::BattleBase()
{
	ReuseInit();
}

BattleBase::~BattleBase()
{
}

BattleStatus BattleBase::GetStatus()const
{
	return m_nStatus;
}

void BattleBase::SetStatus(BattleStatus bs)
{
	m_nStatus = bs;
}

uint32_t BattleBase::GetRound()const
{
	return m_nRound;
}

void BattleBase::SetRound(uint32_t nRound)
{
	m_nRound = nRound;
}

void BattleBase::ReuseInit()
{
	m_nStatus = eBattleStatus_Unknown;
	m_nRound = 0;
}

bool BattleBase::BattleInit(BATTLE_ID_TYPE id, const BattleInfo& bi)
{
	m_nMaxRound = bi.nMaxRound;
	
	return true;
}

bool BattleBase::BattleStart()
{
	return true;
}

bool BattleBase::BattleRun()
{
	//while (!checkBattleFinish())
	//{
	//	initNextActor();
	//	//处理行动前逻辑
	//	processBeforeAction();
	//	//行动前处理完后死亡
	//	auto pActor = getActor();
	//	if (pActor->IsDead())
	//	{
	//		pBattle->SetActor(nullptr);
	//		pBattle->SetSkill(nullptr);
	//		continue;
	//	}
	//	//等待玩家选择
	//	if (pActor->GetFighterStatus() == FS_WAIT)
	//	{
	//		return waitFighterAction(pBattle);
	//	}

	//	//玩家行动
	//	auto nRet = processFighterAct(pBattle);
	//	if (nRet == FIGHT_ERROR)
	//	{
	//		RETURN_FIGHT_ERROR("processFighterAct() return FIGHT_ERROR");
	//	}
	//	else if (nRet == FIGHT_OVER)
	//	{
	//		//pBattle->BattleFinish(true);
	//		break;
	//	}

	//	processAfterAction(pBattle);
	//	//更新死亡状态
	//	processFighterDead(pBattle);

	//	//清空当前玩家
	//	pBattle->SetActor(nullptr);
	//	pBattle->SetSkill(nullptr);
	//}
	//processAfterBattleFinish(pBattle);
	//pBattle->SendActionInfo();
	//pBattle->BattleFinish(true);
	//g_pAuraProcessor->EndAura(pBattle);
	return true;
}

bool BattleBase::BattleEnd()
{
	return true;
}

bool BattleBase::BattleErrorEnd()
{
	return true;
}

