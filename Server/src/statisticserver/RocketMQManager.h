#pragma once
#include "ManagerModule.h"
#include "StatsCommDef.h"
#include "MPTime.h"
#include "RocketMQPushConsumer.h"
#include "RocketMQSyncProducer.h"

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
	std::unordered_map<std::string, RocketMQProducer*> m_mProducers;
	std::unordered_map<std::string, RocketMQConsumer*> m_mConsumers;
};

STATS_MANAGER_MODULE_REG(eStatsMgr_RocketMQ, RocketMQManager);