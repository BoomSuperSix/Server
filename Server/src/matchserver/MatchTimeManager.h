#pragma once
#include "ManagerModule.h"
#include "MatchCommDef.h"
#include "MPTime.h"
#include "TimeManager.h"

class MatchTimeManager final : public ManagerModule
{
public:
	MatchTimeManager();
	~MatchTimeManager();
public:
	virtual bool Awake()override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutDown()override;
	virtual bool ShutDown()override;
public:
	inline const meplay::MPTime& CurrentTime()const { return m_CurTime; };
	inline TimeManager& GetTimeRegister() { return m_TimeMgr; };
private:

	meplay::MPTime m_CurTime;

	TimeManager m_TimeMgr;
};

MATCH_MANAGER_MODULE_REG(eMatchMgr_Time, MatchTimeManager);

//Time
#define BATTLE_CUR_TIME g_pMatchNetProxy->GetModule<MatchTimeManager>(eMatchMgr_Time)->CurrentTime()
#define REGISTER_TIME_EVENT g_pMatchNetProxy->GetModule<MatchTimeManager>(eMatchMgr_Time)->GetTimeRegister().AddTimeEvent

#define _MSEC_TICK_(x) this->ModuleTimeTick::Tick(BATTLE_CUR_TIME,std::chrono::milliseconds(x))

#define _1_SEC_TICK_ this->ModuleTimeTick::Tick(BATTLE_CUR_TIME,std::chrono::seconds(1))
#define _5_SEC_TICK_ this->ModuleTimeTick::Tick(BATTLE_CUR_TIME,std::chrono::seconds(5))
#define _SEC_TICK_(x) this->ModuleTimeTick::Tick(BATTLE_CUR_TIME,std::chrono::seconds(x))

#define _1_MIN_TICK_ this->ModuleTimeTick::Tick(BATTLE_CUR_TIME,std::chrono::minutes(1))
#define _5_MIN_TICK_ this->ModuleTimeTick::Tick(BATTLE_CUR_TIME,std::chrono::minutes(5))
#define _MIN_TICK_(x) this->ModuleTimeTick::Tick(BATTLE_CUR_TIME,std::chrono::minutes(x))

#define _1_HOUR_TICK_ this->ModuleTimeTick::Tick(BATTLE_CUR_TIME,std::chrono::hours(1))
#define _HOUR_TICK_(x) this->ModuleTimeTick::Tick(BATTLE_CUR_TIME,std::chrono::hours(x))