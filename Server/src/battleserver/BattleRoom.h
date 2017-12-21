#pragma once
#include <memory>
#include <google/protobuf/message.h>
#include "MPTime.h"
#include "BattleUserMsg.pb.h"
#include "MPNetDefine.h"

enum BattleRoomType : uint32_t
{
	eBRT_Unknown	= 0,
	eBRT_Test		= 1,
};

class BattleRoom
{
public:
	BattleRoom(BattleRoomType nRoomType,uint64_t nRoomId);
	virtual ~BattleRoom();
public:
	virtual bool RoomAwake() = 0;
	virtual bool RoomAfterAwake() = 0;
	virtual bool RoomExecute() = 0;
	virtual bool RoomBeforeShutDown() = 0;
	virtual bool RoomShutDown() = 0;
	virtual bool AddPlayer(uint64_t nSockIndex) = 0;
	virtual bool DelPlayer(uint64_t nSockIndex) = 0;
public:
	void RoomExecuteBase();
	void AddPlayerBase(uint64_t nSockIndex);
	void DelPlayerBase(uint64_t nSockIndex);
	void AddPlayerOperate(const std::string& sData);

	void Broadcast(uint16_t nMsgId,google::protobuf::Message& msg);

	void ReuseInit(BattleRoomType nRoomType, uint64_t nRoomId);
	void Clear();

	uint32_t GetRoomType()const;
	uint64_t GetRoomId()const;

	void InitFrameData();
	void SendFrameData();
private:
	meplay::MPTime m_CreateTime;
	meplay::MPTime m_UpdateTime;
	uint32_t m_nRoomType;
	uint64_t m_nRoomId;
	uint64_t m_nFrame;

	std::list<MPSOCK> m_vAllPlayers;

	BattleMsg::BattleSingleFrame_S2C m_CurFrameData;
	std::map<uint64_t, BattleMsg::BattleSingleFrame_S2C> m_mAllFrameData;
};
typedef std::shared_ptr<BattleRoom> BattleRoomPtr;

class BattleRoomTest : public BattleRoom
{
public:
	BattleRoomTest(BattleRoomType nRoomType, uint64_t nRoomId);
	virtual ~BattleRoomTest();
public:
	virtual bool RoomAwake()override;
	virtual bool RoomAfterAwake()override;
	virtual bool RoomExecute()override;
	virtual bool RoomBeforeShutDown()override;
	virtual bool RoomShutDown()override;
	virtual bool AddPlayer(uint64_t nSockIndex)override;
	virtual bool DelPlayer(uint64_t nSockIndex)override;
};