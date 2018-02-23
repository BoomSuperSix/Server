#include "ItemManager.h"

ItemManager::ItemManager() : ManagerModule(eGameMgr_Item)
{
}

ItemManager::~ItemManager()
{
}
bool ItemManager::Awake()
{
	GET_XML_DATA("Item", "ID", "MainType", "SubType");
	return true;
}

bool ItemManager::AfterAwake()
{
	return true;
}

bool ItemManager::Execute()
{
	return true;
}

bool ItemManager::BeforeShutDown()
{
	return true;
}

bool ItemManager::ShutDown()
{
	return true;
}
