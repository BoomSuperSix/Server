#include "RocketMQPushConsumer.h"
#include "MPLogger.h"

PushMsgListener::PushMsgListener()
{
}

PushMsgListener::~PushMsgListener()
{
}

ConsumeStatus PushMsgListener::consumeMessage(const std::vector<MQMessageExt> &msgs)
{
	for (size_t i = 0; i < msgs.size(); ++i)
	{
		MP_DEBUG("msg body is %s.", msgs[i].getBody().c_str());
	}

	return CONSUME_SUCCESS;
}

RocketMQPushConsumer::RocketMQPushConsumer(const std::string& sGroupName)
	: RocketMQConsumer()
	, m_PushConsumer(sGroupName)
	, m_sGroupName(sGroupName)
{
}

RocketMQPushConsumer::~RocketMQPushConsumer()
{
}
bool RocketMQPushConsumer::Awake(
	const std::string& sNameSrvAddr,
	const std::string& sTopic,
	const std::string& sTag
)
{ 
	m_sNameSrvAddr = sNameSrvAddr;
	m_sTopic = sTopic;
	m_sTag = sTag;

	m_PushConsumer.setNamesrvAddr(sNameSrvAddr);
	m_PushConsumer.setGroupName(m_sGroupName);
	//m_PushConsumer.setConsumeFromWhere(CONSUME_FROM_LAST_OFFSET);
	m_PushConsumer.setConsumeFromWhere(CONSUME_FROM_LAST_OFFSET_AND_FROM_MIN_WHEN_BOOT_FIRST);
	//m_PushConsumer.
	m_PushConsumer.subscribe(sTopic, sTag);
	m_PushConsumer.registerMessageListener(&m_PushListener);

	return true;
}

bool RocketMQPushConsumer::AfterAwake()
{ 
	m_PushConsumer.start();
	return true;
}

bool RocketMQPushConsumer::Execute()
{ 
	return true;
}

bool RocketMQPushConsumer::BeforeShutdown()
{ 
	return true;
}

bool RocketMQPushConsumer::Shutdown()
{ 
	m_PushConsumer.shutdown();
	return true;
}
