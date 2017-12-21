#include "MatchTimeManager.h"

MatchTimeManager::MatchTimeManager()
	: ManagerModule(eMatchMgr_Time)
{
}

MatchTimeManager::~MatchTimeManager()
{
}
bool MatchTimeManager::Awake()
{
	return true;
}

bool MatchTimeManager::AfterAwake()
{
	return true;
}

bool MatchTimeManager::Execute()
{
	m_CurTime.Now();

	m_TimeMgr.Run();
	return true;
}

bool MatchTimeManager::BeforeShutDown()
{
	return true;
}

bool MatchTimeManager::ShutDown()
{
	return true;
}