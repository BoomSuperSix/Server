#include "RankManager.h"

RankManager::RankManager() : ManagerModule(eMatchMgr_Rank)
{

}

RankManager::~RankManager()
{
}

bool RankManager::Awake()
{
	return true;
}

bool RankManager::AfterAwake()
{
	return true;
}

bool RankManager::Execute()
{
	return true;
}

bool RankManager::BeforeShutDown()
{
	return true;
}

bool RankManager::ShutDown()
{
	return true;
}
