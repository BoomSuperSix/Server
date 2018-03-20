#pragma once
#include "MPGUID.h"
#include "BattleCommDef.h"

struct BattleInfo
{
	MPGUID lAtkUserId;
	MPGUID lDefUserId;
	int nBattleId;//战场ID
	int nBattleType;//战斗类型
	bool bAtkAuto;
	bool bDefAuto;
	bool bNotify;
	BattleGroup vAtkFighterList;
	BattleGroup vDefFighterList;
	int nMaxRound;
};