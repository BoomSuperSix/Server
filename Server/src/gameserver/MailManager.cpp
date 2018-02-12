#include "MailManager.h"
#include "AStarPathFinder.h"
#include "XmlManager.h"

MailManager::MailManager() : ManagerModule(eGameMgr_Mail)
{
}

MailManager::~MailManager()
{
}

bool MailManager::Awake()
{
	//std::string sFile = "../xml/Article.xml";
	//auto vData = g_pXmlMgr->ReadTableT_IMPL(sFile, std::make_tuple("id", "name", "level", "isExchage"));
	//auto vData2 = GET_XML_DATA("Article", "id", "name", "level", "isExchage");

	//AStarPathFinder finder([](const POS_TYPE)->bool { return true; });
	//finder.TestMe();
	return true;
}

bool MailManager::AfterAwake()
{
	return true;
}

bool MailManager::Execute()
{
	return true;
}

bool MailManager::BeforeShutDown()
{
	return true;
}

bool MailManager::ShutDown()
{
	return true;
}