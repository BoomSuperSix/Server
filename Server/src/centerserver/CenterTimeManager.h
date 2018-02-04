#pragma once
#include "ManagerModule.h"
#include "CenterCommDef.h"
#include "MPTime.h"
#include "TimeManager.h"

class CenterTimeManager final : public ManagerModule
{
public:
	CenterTimeManager();
	~CenterTimeManager();
public:
	virtual bool Awake()override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutDown()override;
	virtual bool ShutDown()override;
public:
	inline const meplay::MPTime& CurrentTime()const { return m_CurTime; };
	inline TimeManager& GetTimeRegister() { return m_TimeMgr; };
public:
	
private:
	meplay::MPTime m_CurTime;

	TimeManager m_TimeMgr;
};

CENTER_MANAGER_MODULE_REG(eCenterMgr_Time,CenterTimeManager);
