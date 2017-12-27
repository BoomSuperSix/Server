#pragma once
#include "MatchCommDef.h"
#include "ManagerModule.h"

class RankManager : public ManagerModule
{
public:
	RankManager();
	~RankManager();
public:
	virtual bool Awake()override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutDown()override;
	virtual bool ShutDown()override;
public:
private:
};

MATCH_MANAGER_MODULE_REG(eMatchMgr_Rank, RankManager);