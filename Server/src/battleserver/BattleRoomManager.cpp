#include "BattleRoomManager.h"
#include "BattleTimeManager.h"


uint32_t BattleRoomManager::m_nSeed = 0;

BattleRoomManager::BattleRoomManager() : ManagerModule(eBattleMgr_BattleRoom),ModuleTimeTick()
{
}

BattleRoomManager::~BattleRoomManager()
{
}

bool BattleRoomManager::Awake()
{
	REGISTER_BATTLE_USER(this, BattleMsg::eBattleMsg_Login, BattleRoomManager::OnBattleUserLogin);
	REGISTER_BATTLE_USER(this, BattleMsg::eBattleMsg_LoadOK, BattleRoomManager::OnBattleUserLoadOK);
	REGISTER_BATTLE_USER(this, BattleMsg::eBattleMsg_GameStart, BattleRoomManager::OnBattleUserGameStart);
	REGISTER_BATTLE_USER(this, BattleMsg::eBattleMsg_UserOperate, BattleRoomManager::OnBattleUserOperate);
	REGISTER_BATTLE_USER(this, BattleMsg::eBattleMsg_Logout, BattleRoomManager::OnBattleUserLogout);

	m_nMaxRoom = 1024;

	return true;
}

bool BattleRoomManager::AfterAwake()
{
	//for test
	AddBattleRoom(eBRT_Test);
	return true;
}

bool BattleRoomManager::Execute()
{
	if (_1_SEC_TICK_)
	{
		m_nSeed = 0;
	}

	//user server frame tick
	for (auto&&[nRoomId, pRoom] : m_mBattleRooms)
	{
		pRoom->RoomExecuteBase();
	}
	return true;
}

bool BattleRoomManager::BeforeShutDown()
{
	return true;
}

bool BattleRoomManager::ShutDown()
{
	return true;
}

void BattleRoomManager::OnBattleUserLogin(const std::string& sData, const uint64_t nSockIndex)
{
	BattleMsg::BattleUserLogin_C2S inMsg;
	if (!inMsg.ParseFromString(sData))
	{
		return;
	}

	inMsg.uid();
	inMsg.room();
	BattleMsg::BattleUserLogin_S2C outMsg;
	auto nRoomId = GetTestRoomId();
	auto pRoom = GetRoomByRoomId(nRoomId);
	if (pRoom == nullptr)
	{
		outMsg.set_errcode(BattleMsg::eBEC_Fail);
	}
	else
	{
		outMsg.set_errcode(BattleMsg::eBEC_Success);
	}
	pRoom->Broadcast(BattleMsg::eBattleMsg_Login, outMsg);
}

void BattleRoomManager::OnBattleUserLoadOK(const std::string& sData, const uint64_t nSockIndex)
{
	BattleMsg::BattleUserLoadOK_C2S inMsg;
	if (!inMsg.ParseFromString(sData))
	{
		return;
	}

	BattleMsg::BattleUserLoadOK_S2C outMsg;
	outMsg.set_uid(inMsg.uid());

	auto nRoomId = GetTestRoomId();
	auto pRoom = GetRoomByRoomId(nRoomId);
	if (pRoom != nullptr)
	{
		pRoom->Broadcast(BattleMsg::eBattleMsg_LoadOK, outMsg);
	}

}

void BattleRoomManager::OnBattleUserOperate(const std::string& sData, const uint64_t nSockIndex)
{
	//if (!inMsg.ParseFromString(sData))
	//{
	//	return;
	//}

	////BattleMsg::BattleUserOperate_C2S inMsg;
	//auto nRoomId = GetTestRoomId();
	//auto pRoom = GetRoomByRoomId(nRoomId);
	//if (pRoom == nullptr)
	//{
	//	return;
	//}
	//pRoom->AddPlayerOperate(inMsg.data());
}

void BattleRoomManager::OnBattleUserGameStart(const std::string& sData, const uint64_t nSockIndex)
{
}

void BattleRoomManager::OnBattleUserLogout(const std::string& sData, const uint64_t nSockIndex)
{
}

uint64_t BattleRoomManager::AddBattleRoom(BattleRoomType nRoomType)
{
	uint64_t nRoomId = genNewRoomId();
	BattleRoomPtr pRoom(nullptr);
	switch (nRoomType)
	{
	case eBRT_Test:
	{
		pRoom = m_TestRoomPool.Get<BattleRoom>(nRoomType, nRoomId);
	}
	default:
		break;
	}
	if (pRoom == nullptr)
	{
		return 0;
	}

	if (!m_mBattleRooms.emplace(pRoom->GetRoomId(), pRoom).second)
	{
		return 0;
	}

	return pRoom->GetRoomId();
}
bool BattleRoomManager::DelBattleRoom(uint64_t nRoomId)
{
	return m_mBattleRooms.erase(nRoomId) > 0;
}

void BattleRoomManager::AddBattleRoomUser(uint64_t nSockIndex)
{
}

void BattleRoomManager::DelBattleRoomUser(uint64_t nSockIndex)
{
}

uint64_t BattleRoomManager::genNewRoomId()const
{
	if (m_nSeed >= m_nMaxRoom)
	{
		return 0;
	}
	return MAKE_U64(BATTLE_CUR_TIME.CurrentSec(), m_nSeed++);
}

uint64_t BattleRoomManager::GetTestRoomId()const
{
	for (auto&&[id, pRoom] : m_mBattleRooms)
	{
		return pRoom->GetRoomId();
	}
	return 0;
}

BattleRoomPtr BattleRoomManager::GetRoomByRoomId(uint64_t nRoomId)
{
	if (auto it = m_mBattleRooms.find(nRoomId); it != m_mBattleRooms.end())
	{
		return it->second;
	}
	return nullptr;
}

BattleRoomPtr BattleRoomManager::GetRoomByFD(uint64_t nSockIndex)
{
	auto nRoomId = GetRoomIdByFD(nSockIndex);
	return GetRoomByRoomId(nRoomId);
}

uint64_t BattleRoomManager::GetRoomIdByFD(uint64_t nSockIndex)const
{
	if (auto it = m_mUID2RoomId.find(nSockIndex); it != m_mUID2RoomId.end())
	{
		return it->second;
	}
	return 0;
}