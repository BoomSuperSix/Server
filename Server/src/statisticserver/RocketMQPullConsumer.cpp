#include "RocketMQPullConsumer.h"
#include "MPLogger.h"

RocketMQPullConsumer::RocketMQPullConsumer(const std::string& sGroupName)
	: RocketMQConsumer()
	, m_PullConsumer(sGroupName)
	, m_sGroupName(sGroupName)
{
}

RocketMQPullConsumer::~RocketMQPullConsumer()
{
}
bool RocketMQPullConsumer::Awake(
	const std::string& sNameSrvAddr,
	const std::string& sTopic,
	const std::string& sTag
)
{
	m_sNameSrvAddr = sNameSrvAddr;
	m_sTopic = sTopic;
	m_sTag = sTag;

	m_PullConsumer.setNamesrvAddr(sNameSrvAddr);
	m_PullConsumer.setGroupName(m_sGroupName);
	m_PullConsumer.registerMessageQueueListener(sTopic, nullptr);

	return true;
}

bool RocketMQPullConsumer::AfterAwake()
{
	m_PullConsumer.start();
	return true;
}

bool RocketMQPullConsumer::Execute()
{
	return consumeMessage();
}

bool RocketMQPullConsumer::BeforeShutdown()
{
	return true;
}

bool RocketMQPullConsumer::Shutdown()
{
	m_PullConsumer.shutdown();
	return true;
}

bool RocketMQPullConsumer::consumeMessage()
{
	if (1)
	{
		return true;
	}

	std::vector<MQMessageQueue> mqs;

	m_PullConsumer.fetchSubscribeMessageQueues(m_sTopic, mqs);
	{
		auto iter = mqs.begin();
		for (; iter != mqs.end(); ++iter)
		{
			MP_DEBUG("mq : %s", iter->toString().c_str());
		}
	}

	auto start = std::chrono::system_clock::now();
	auto iter = mqs.begin();
	for (; iter != mqs.end(); ++iter)
	{
		MQMessageQueue mq = (*iter);
		// if cluster model
		// putMessageQueueOffset(mq, g_consumer.fetchConsumeOffset(mq,true));
		// if broadcast model
		// putMessageQueueOffset(mq, your last consume offset);

		bool noNewMsg = false;
		do
		{
			PullResult result = m_PullConsumer.pull(mq, "*", 0, 32);
			MP_DEBUG("MsgFound %d.", result.msgFoundList.size());
			// if pull request timeout or received NULL response, pullStatus will be
			// setted to BROKER_TIMEOUT,
			// And nextBeginOffset/minOffset/MaxOffset will be setted to 0
			if (result.pullStatus != BROKER_TIMEOUT)
			{
				//putMessageQueueOffset(mq, result.nextBeginOffset);
				testPrintResult(&result);
			}
			else
			{
				MP_DEBUG("broker timeout occur");
			}
			switch (result.pullStatus)
			{
			case FOUND:
			case NO_MATCHED_MSG:
			case OFFSET_ILLEGAL:
			case BROKER_TIMEOUT:
				break;
			case NO_NEW_MSG:
				noNewMsg = true;
				break;
			default:
				break;
			}
		}
		while (!noNewMsg);
	}

	/*auto end = std::chrono::system_clock::now();
	auto duration =
		std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "msg count: " << g_msgCount.load() << "\n";
	std::cout
		<< "per msg time: " << duration.count() / (double)g_msgCount.load()
		<< "ms \n"
		<< "========================finished==============================\n";

	*/
	return true;
}

void RocketMQPullConsumer::testPrintResult(rocketmq::PullResult* result)
{
	std::cout << result->toString() << std::endl;
	if (result->pullStatus == rocketmq::FOUND)
	{
		MP_DEBUG("%s", result->toString().c_str());
		std::vector<rocketmq::MQMessageExt>::iterator it =
			result->msgFoundList.begin();
		for (; it != result->msgFoundList.end(); ++it)
		{
			MP_DEBUG("=======================================================");
			MP_DEBUG("%s", it->toString().c_str());
		}
	}
}