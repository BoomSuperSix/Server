#pragma once
#include "RocketMQConsumer.h"
#include "DefaultMQPullConsumer.h"

using namespace rocketmq;

class RocketMQPullConsumer final : public RocketMQConsumer
{
public:
	RocketMQPullConsumer(const std::string& sGroupName);
	~RocketMQPullConsumer();
public:
	virtual bool Awake(
		const std::string& sNameSrvAddr,
		const std::string& sTopic,
		const std::string& sTag
	)override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutdown()override;
	virtual bool Shutdown()override;
private:
	bool consumeMessage();
	void testPrintResult(rocketmq::PullResult* result);
private:
	DefaultMQPullConsumer m_PullConsumer;

	std::string m_sNameSrvAddr;
	std::string m_sGroupName;
	std::string m_sTopic;
	std::string m_sTag;
};