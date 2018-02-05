#pragma once
#include <string>

struct StatMsg
{
	std::string sTag;
	std::string sBody;
};

class RocketMQProducer
{
public:
	RocketMQProducer();
	~RocketMQProducer();
public:
	virtual bool Awake(
		const std::string& sNameSrvAddr,
		const std::string& sTopic
	) = 0;
	virtual bool AfterAwake() = 0;
	virtual bool Execute() = 0;
	virtual bool BeforeShutdown() = 0;
	virtual bool Shutdown() = 0;
private:
};