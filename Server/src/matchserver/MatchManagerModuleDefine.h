#pragma once
#include <stdint.h>

enum Enum_MatchManagerModule : int32_t
{
	eMatchMgr_Unknown = -1,
	eMatchMgr_Begin = 0,
	eMatchMgr_CenterServer = 0,
	eMatchMgr_SuperServer = 1,
	eMatchMgr_Time = 2,
	eMatchMgr_Rank = 3,
	eMatchMgr_MatchUser = 4,

	eMatchMgr_End
};