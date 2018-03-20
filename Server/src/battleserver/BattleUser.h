#pragma once
#include <memory>

class BattleUser
{
public:
	BattleUser(uint64_t nSockIndex,uint64_t uid,uint64_t nRoomId);
	~BattleUser();
public:
	void ReuseInit(uint64_t nSockIndex,uint64_t uid,uint64_t nRoomId);

	uint64_t GetFD()const;
	uint64_t GetUID()const;
	uint64_t GetRoomId()const;
private:
	uint64_t m_nSockIndex;
	uint64_t m_UID;
	uint64_t m_nRoomId;
};

typedef std::shared_ptr<BattleUser> BattleUserPtr;