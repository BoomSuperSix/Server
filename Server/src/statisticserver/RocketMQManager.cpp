#include "RocketMQManager.h"
#include "MPLogger.h"

RocketMQManager::RocketMQManager()
	: ManagerModule(eStatsMgr_RocketMQ)
    ,m_producer("test_group_name")
{
}

RocketMQManager::~RocketMQManager()
{
}
bool RocketMQManager::Awake()
{
	m_producer.setNamesrvAddr("172.24.3.2:9876");
    m_producer.start();
	return true;
}

bool RocketMQManager::AfterAwake()
{
	return true;
}

bool RocketMQManager::Execute()
{
    if(1)
    {
        MQMessage msg("test_topic",  // topic
                "*",          // tag
                "this is body");  // body
        SendResult sendResult = m_producer.send(msg,false);
        if(sendResult.getSendStatus() != SEND_OK)
        {
            sendResult.getMsgId().c_str();
        }
    }
    return true;
}

bool RocketMQManager::BeforeShutDown()
{
    return true;
}

bool RocketMQManager::ShutDown()
{
    m_producer.shutdown();
    return true;
}
