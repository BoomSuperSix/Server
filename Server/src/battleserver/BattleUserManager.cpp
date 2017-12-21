#include "BattleUserManager.h"
#include "BattleRoomManager.h"

BattleUserManager::BattleUserManager() : ManagerModule(eBattleMgr_BattleUser)
{
}

BattleUserManager::~BattleUserManager()
{
}

bool BattleUserManager::Awake()
{
	REGISTER_BATTLE_USER(this, BattleMsg::eBattleMsg_Login, BattleUserManager::OnBattleUserLogin);

	return true;
}

bool BattleUserManager::AfterAwake()
{
	return true;
}

bool BattleUserManager::Execute()
{
	return true;
}

bool BattleUserManager::BeforeShutDown()
{
	return true;
}

bool BattleUserManager::ShutDown()
{
	return true;
}

void BattleUserManager::AddBattleUser(uint64_t nSockIndex)
{
	if (!m_mTempBattleUsers.emplace(nSockIndex, meplay::MPTime()).second)
	{
		MP_ERROR("Same Sock Index");
	}
}

void BattleUserManager::DelBattleUser(uint64_t nSockIndex)
{
	m_mTempBattleUsers.erase(nSockIndex);
	m_mBattleUsers.erase(nSockIndex);
}

void BattleUserManager::OnBattleUserLogin(const std::string& sData, const uint64_t nSockIndex)
{
	BattleMsg::BattleUserLogin_C2S inMsg;
	if (!inMsg.ParseFromString(sData))
	{
		MP_ERROR("[%llu] ParseError! Login Failed!", nSockIndex);
		return;
	}
	
	if (m_mTempBattleUsers.erase(nSockIndex) > 0)
	{
		MP_ERROR("[%llu] NotFound Temp BattleUser ! Login Failed!", nSockIndex);
		return;
	}
		
	auto pRoomMgr = g_pBattleNetProxy->GetModule<BattleRoomManager>(eBattleMgr_BattleRoom);
	
	auto pBattleUser = m_BattleUserPool.Get(nSockIndex, inMsg.uid(), pRoomMgr->GetTestRoomId());
	if (pBattleUser == nullptr)
	{
		//impossible
		return;
	}

	m_mBattleUsers.emplace(nSockIndex, pBattleUser);
}