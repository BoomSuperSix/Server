#pragma once
#include <memory>
#include "MPTime.h"

class StatsServer final
{
public:
	StatsServer(uint64_t nSockIndex, const char* ip, int nPort);
	~StatsServer();
public:
	inline const std::string& GetIP()const { return m_sIP; }
	inline const int GetPort()const { return m_nPort; }
public:
	void ReuseInit(uint64_t nSockIndex, const char* ip, int nPort);
	void Clear();

private:
	uint64_t m_nSockIndex;
	std::string m_sIP;
	int	m_nPort;
	meplay::MPTime m_LogonTime;
	meplay::MPTime m_VerifyTime;
};


typedef std::shared_ptr<StatsServer> StatsServerPtr;