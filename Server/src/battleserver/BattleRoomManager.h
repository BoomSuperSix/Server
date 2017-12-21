#pragma once
#include "BattleCommDef.h"
#include "BattleRoom.h"
#include "MPMemoryPool.h"
#include "ModuleTimeTick.h"

class BattleRoomManager final : public ManagerModule,public ModuleTimeTick
{
public:
	BattleRoomManager();
	~BattleRoomManager();
public:
	virtual bool Awake()override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutDown()override;
	virtual bool ShutDown()override;
public:
	//
	void OnBattleUserOperate(const std::string& sData, const uint64_t nSockIndex);

	uint64_t AddBattleRoom(BattleRoomType nRoomType);
	bool DelBattleRoom(uint64_t nRoomId);
	void AddBattleRoomUser(uint64_t nSockIndex);
	void DelBattleRoomUser(uint64_t nSockIndex);

	BattleRoomPtr GetRoomByRoomId(uint64_t nRoomId);
	BattleRoomPtr GetRoomByFD(uint64_t nSockIndex);
	uint64_t GetRoomIdByFD(uint64_t nSockIndex)const;
private:
	uint64_t genNewRoomId()const;
private:
	std::unordered_map<uint64_t, BattleRoomPtr> m_mBattleRooms;
	std::unordered_map<uint64_t, uint64_t> m_mUID2RoomId;

	static uint32_t m_nSeed;
	uint32_t m_nMaxRoom;

	MPMemoryPool<BattleRoomTest> m_TestRoomPool;

public:
	//This is for test
	uint64_t GetTestRoomId()const;
};

BATTLE_MANAGER_MODULE_REG(eBattleMgr_BattleRoom, BattleRoomManager);
