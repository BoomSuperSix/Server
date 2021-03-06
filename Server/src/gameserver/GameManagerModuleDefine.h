#pragma once
#include <stdint.h>

enum Enum_GameManagerModule : int32_t
{
	eGameMgr_Unknown		= -1,
	eGameMgr_Begin			= 0,
	eGameMgr_Time			= 0,
	eGameMgr_SuperServer	= 1,
	eGameMgr_GateServer		= 2,
	eGameMgr_StatsServer	= 3,
	eGameMgr_GameUser		= 4,
	eGameMgr_DBServer		= 5,
	eGameMgr_TimeStamp		= 6,
	eGameMgr_Refresh		= 7,
	eGameMgr_Mail			= 8,
	eGameMgr_Item			= 9,

	eGameMgr_End
};