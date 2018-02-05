#pragma once
#include "RocketMQProducer.h"
#include "DefaultMQProducer.h"
#include <queue>

using namespace rocketmq;

class RocketMQSyncProducer final : public RocketMQProducer
{
public:
	RocketMQSyncProducer(const std::string& sGroupName);
	~RocketMQSyncProducer();
public:
	virtual bool Awake(
		const std::string& sNameSrvAddr,
		const std::string& sTopic
	)override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutdown()override;
	virtual bool Shutdown()override;
private:
	DefaultMQProducer m_Producer;

	std::queue<StatMsg> m_vStatMsg;
	std::string m_sGroupName;
	std::string m_sNameSrvAddr;
	std::string m_sTopic;
};