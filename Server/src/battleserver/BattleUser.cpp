#include "BattleUser.h"

BattleUser::BattleUser(uint64_t nSockIndex,uint64_t uid,uint64_t nRoomId)
{
	ReuseInit(nSockIndex,uid,nRoomId);
}

BattleUser::~BattleUser()
{
}

void BattleUser::ReuseInit(uint64_t nSockIndex,uint64_t uid,uint64_t nRoomId)
{
	m_nSockIndex = nSockIndex;
	m_UID = uid;
	m_nRoomId = nRoomId;
}

void BattleUser::Clear()
{
}

uint64_t BattleUser::GetFD()const
{
	return m_nSockIndex;
}

uint64_t BattleUser::GetUID()const
{
	return m_UID;
}

uint64_t BattleUser::GetRoomId()const
{
	return m_nRoomId;
}
