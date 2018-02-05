#pragma once
#include <string>

class RocketMQConsumer
{
public:
	RocketMQConsumer();
	~RocketMQConsumer();
public:
	virtual bool Awake(
		const std::string& sNameSrvAddr,
		const std::string& sTopic,
		const std::string& sTag
	) = 0;
	virtual bool AfterAwake() = 0;
	virtual bool Execute() = 0;
	virtual bool BeforeShutdown() = 0;
	virtual bool Shutdown() = 0;
private:

};