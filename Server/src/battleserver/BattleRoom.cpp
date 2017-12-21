#include "BattleRoom.h"
#include "BattleNetProxy.h"
#include "BattleTimeManager.h"

BattleRoom::BattleRoom(BattleRoomType nRoomType, uint64_t nRoomId)
	: m_nRoomType(nRoomType),m_nRoomId(nRoomId),m_nFrame(0)
{
	m_CreateTime = BATTLE_CUR_TIME;
	m_UpdateTime = BATTLE_CUR_TIME;
}

BattleRoom::~BattleRoom()
{
}

void BattleRoom::ReuseInit(BattleRoomType nRoomType, uint64_t nRoomId)
{
	m_nRoomType = nRoomType;
	m_nRoomId = nRoomId;
	m_CreateTime = BATTLE_CUR_TIME;
	m_CurFrameData.Clear();
	m_mAllFrameData.clear();
}

void BattleRoom::Clear()
{
	m_nRoomType = eBRT_Unknown;
	m_nRoomId = 0;
}

void BattleRoom::RoomExecuteBase()
{
	m_UpdateTime = BATTLE_CUR_TIME;
	InitFrameData();
	RoomExecute();
	SendFrameData();
	++m_nFrame;
}

void BattleRoom::AddPlayerBase(uint64_t nSockIndex)
{
	AddPlayer(nSockIndex);
}

void BattleRoom::DelPlayerBase(uint64_t nSockIndex)
{
	DelPlayer(nSockIndex);
}

void BattleRoom::AddPlayerOperate(const std::string& sData)
{
	m_CurFrameData.add_datas(sData);
}

void BattleRoom::InitFrameData()
{
	m_CurFrameData.clear_datas();
	m_CurFrameData.set_frame_index(m_nFrame);
	m_CurFrameData.set_milli_second(m_UpdateTime.CurrentMSec());
}

void BattleRoom::SendFrameData()
{
	if (m_CurFrameData.datas_size() == 0)
	{
		return;
	}
	Broadcast(BattleMsg::eBattleMsg_SingleFrame, m_CurFrameData);
	m_mAllFrameData.emplace(m_nFrame, m_CurFrameData);
}

void BattleRoom::Broadcast(uint16_t nMsgId,google::protobuf::Message& msg)
{
	SEND2BATTLE_USER(m_vAllPlayers, nMsgId, msg);
}

uint32_t BattleRoom::GetRoomType()const
{
	return m_nRoomType;
}

uint64_t BattleRoom::GetRoomId()const
{
	return m_nRoomId;
}

BattleRoomTest::BattleRoomTest(BattleRoomType nRoomType, uint64_t nRoomId)
	: BattleRoom(nRoomType,nRoomId)
{
}

BattleRoomTest::~BattleRoomTest()
{
}

bool BattleRoomTest::RoomAwake()
{
	return true;
}

bool BattleRoomTest::RoomAfterAwake()
{
	return true;
}

bool BattleRoomTest::RoomExecute()
{
	return true;
}

bool BattleRoomTest::RoomBeforeShutDown()
{
	return true;
}

bool BattleRoomTest::RoomShutDown()
{
	return true;
}

bool BattleRoomTest::AddPlayer(uint64_t nSockIndex)
{
	return true;
}

bool BattleRoomTest::DelPlayer(uint64_t nSockIndex)
{
	return true;
}

