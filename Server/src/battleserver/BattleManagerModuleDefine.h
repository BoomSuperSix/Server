#pragma once
#include <stdint.h>

enum Enum_BattleManagerModule : int32_t
{
	eBattleMgr_Unknown = -1,
	eBattleMgr_Begin = 0,
	eBattleMgr_CenterServer = 0,
	eBattleMgr_GameServer = 1,
	eBattleMgr_Time = 2,

	eBattleMgr_End
};