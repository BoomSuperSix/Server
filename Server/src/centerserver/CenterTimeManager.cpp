#include "CenterTimeManager.h"

CenterTimeManager::CenterTimeManager()
	: ManagerModule(eCenterMgr_Time)
{
}

CenterTimeManager::~CenterTimeManager()
{
}
bool CenterTimeManager::Awake()
{
	return true;
}

bool CenterTimeManager::AfterAwake()
{
	return true;
}

bool CenterTimeManager::Execute()
{
	m_CurTime.Now();
	m_TimeMgr.Run();
	return true;
}

bool CenterTimeManager::BeforeShutDown()
{
	return true;
}

bool CenterTimeManager::ShutDown()
{
	return true;
}