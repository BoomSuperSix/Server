#pragma once
#include "RocketMQConsumer.h"
#include "DefaultMQPushConsumer.h"

using namespace rocketmq;

class PushMsgListener : public MessageListenerConcurrently
{
public:
	PushMsgListener();
	virtual ~PushMsgListener();
public:
	virtual ConsumeStatus consumeMessage(const std::vector<MQMessageExt> &msgs)override;
};

class RocketMQPushConsumer final : public RocketMQConsumer
{
public:
	RocketMQPushConsumer(const std::string& sGroupName);
	~RocketMQPushConsumer();
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
	DefaultMQPushConsumer m_PushConsumer;

	std::string m_sNameSrvAddr;
	std::string m_sGroupName;
	std::string m_sTopic;
	std::string m_sTag;

	PushMsgListener m_PushListener;
};