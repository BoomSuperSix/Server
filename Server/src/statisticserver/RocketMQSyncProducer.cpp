#include "RocketMQSyncProducer.h"

RocketMQSyncProducer::RocketMQSyncProducer(const std::string& sGroupName)
	: RocketMQProducer() 
	, m_Producer(sGroupName)
	, m_sGroupName(sGroupName)
{
}

RocketMQSyncProducer::~RocketMQSyncProducer()
{
}

bool RocketMQSyncProducer::Awake(
	const std::string& sNameSrvAddr,
	const std::string& sTopic
)
{
	m_sNameSrvAddr = sNameSrvAddr;
	m_sTopic = sTopic;

	m_Producer.setNamesrvAddr(sNameSrvAddr);

	return true;
}

bool RocketMQSyncProducer::AfterAwake()
{
	m_Producer.start();

	return true;
}

bool RocketMQSyncProducer::Execute()
{
	if (0)
	{
		StatMsg tmp;
		tmp.sBody = "This is body.";
		tmp.sTag = "*";
		m_vStatMsg.emplace(tmp);
	}
	while (!m_vStatMsg.empty())
	{
		auto& statMsg = m_vStatMsg.front();
		MQMessage msg(m_sTopic, statMsg.sTag, statMsg.sBody); 
		SendResult sendResult = m_Producer.send(msg, false);
		if (sendResult.getSendStatus() != SEND_OK)
		{
			return false;
		}
		m_vStatMsg.pop();
	}
	return true;
}

bool RocketMQSyncProducer::BeforeShutdown()
{
	return true;
}

bool RocketMQSyncProducer::Shutdown()
{
	m_Producer.shutdown();
	return true;
}
