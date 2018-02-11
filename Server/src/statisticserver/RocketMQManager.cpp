#include "RocketMQManager.h"
#include "MPLogger.h"

RocketMQManager::RocketMQManager()
	: ManagerModule(eStatsMgr_RocketMQ)
{
}

RocketMQManager::~RocketMQManager()
{
}
bool RocketMQManager::Awake()
{
	RocketMQProducer* pProducer = new RocketMQSyncProducer("test_group_name");
	m_mProducers.emplace("test_group_name", pProducer);
	//RocketMQConsumer* pConsumer = new RocketMQPushConsumer("test_group_name");
	RocketMQConsumer* pConsumer = new RocketMQPullConsumer("test_group_name");
	m_mConsumers.emplace("test_group_name", pConsumer);

	for (auto& pi : m_mProducers)
	{
		auto pProducer = pi.second;
		pProducer->Awake("172.24.3.2:9876", "test_topic_2");
	}

	for (auto& ci : m_mConsumers)
	{
		auto pConsumer = ci.second;
		pConsumer->Awake("172.24.3.2:9876", "test_topic", "*");
	}

	return true;
}

bool RocketMQManager::AfterAwake()
{
	for (auto& pi : m_mProducers)
	{
		auto pProducer = pi.second;
		pProducer->AfterAwake();
	}

	for (auto& ci : m_mConsumers)
	{
		auto pConsumer = ci.second;
		pConsumer->AfterAwake();
	}

	return true;
}

bool RocketMQManager::Execute()
{
	for (auto& pi : m_mProducers)
	{
		auto pProducer = pi.second;
		pProducer->Execute();
	}

	for (auto& ci : m_mConsumers)
	{
		auto pConsumer = ci.second;
		pConsumer->Execute();
	}
    return true;
}

bool RocketMQManager::BeforeShutDown()
{
	for (auto& pi : m_mProducers)
	{
		auto pProducer = pi.second;
		pProducer->BeforeShutdown();
	}

	for (auto& ci : m_mConsumers)
	{
		auto pConsumer = ci.second;
		pConsumer->BeforeShutdown();
	}
    return true;
}

bool RocketMQManager::ShutDown()
{
	for (auto& pi : m_mProducers)
	{
		auto pProducer = pi.second;
		pProducer->Shutdown();
	}

	for (auto& ci : m_mConsumers)
	{
		auto pConsumer = ci.second;
		pConsumer->Shutdown();
	}
    return true;
}
