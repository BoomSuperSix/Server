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
	//	//�����ж�ǰ�߼�
	//	processBeforeAction();
	//	//�ж�ǰ�����������
	//	auto pActor = getActor();
	//	if (pActor->IsDead())
	//	{
	//		pBattle->SetActor(nullptr);
	//		pBattle->SetSkill(nullptr);
	//		continue;
	//	}
	//	//�ȴ����ѡ��
	//	if (pActor->GetFighterStatus() == FS_WAIT)
	//	{
	//		return waitFighterAction(pBattle);
	//	}

	//	//����ж�
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
	//	//��������״̬
	//	processFighterDead(pBattle);

	//	//��յ�ǰ���
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

