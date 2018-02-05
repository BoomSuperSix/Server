#pragma once
#include "ManagerModule.h"
#include "StatsCommDef.h"
#include "MPTime.h"
#include "DefaultMQProducer.h"

using namespace rocketmq;

class RocketMQManager final : public ManagerModule
{
public:
	RocketMQManager();
	~RocketMQManager();
public:
	virtual bool Awake()override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutDown()override;
	virtual bool ShutDown()override;
public:
private:
    DefaultMQProducer m_producer;
};

STATS_MANAGER_MODULE_REG(eStatsMgr_RocketMQ, RocketMQManager);