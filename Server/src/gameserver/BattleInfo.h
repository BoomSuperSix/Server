#pragma once
#include "MPGUID.h"
#include "BattleCommDef.h"

struct BattleInfo
{
	MPGUID lAtkUserId;
	MPGUID lDefUserId;
	int nBattleId;//ս��ID
	int nBattleType;//ս������
	bool bAtkAuto;
	bool bDefAuto;
	bool bNotify;
	BattleGroup vAtkFighterList;
	BattleGroup vDefFighterList;
	int nMaxRound;
};