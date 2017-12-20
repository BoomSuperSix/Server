#include "BattleTimeManager.h"

BattleTimeManager::BattleTimeManager()
	: ManagerModule(eBattleMgr_Time)
{
}

BattleTimeManager::~BattleTimeManager()
{
}
bool BattleTimeManager::Awake()
{
	return true;
}

bool BattleTimeManager::AfterAwake()
{
	return true;
}

bool BattleTimeManager::Execute()
{
	m_CurTime.Now();

	m_TimeMgr.Run();
	return true;
}

bool BattleTimeManager::BeforeShutDown()
{
	return true;
}

bool BattleTimeManager::ShutDown()
{
	return true;
}