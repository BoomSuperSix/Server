#pragma once
#include "BattleCommDef.h"

class CenterServerManager final : public ManagerModule
{
public:
	CenterServerManager();
	~CenterServerManager();
public:
	virtual bool Awake()override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutDown()override;
	virtual bool ShutDown()override;
public:
private:
};

BATTLE_MANAGER_MODULE_REG(eBattleMgr_CenterServer, CenterServerManager);