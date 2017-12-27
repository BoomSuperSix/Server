#pragma once
#include "NetProxy.h"
#include "MPThread.h"
#include "ManagerModuleManager.h"
#include "CommDef.h"
#include "MPSingleton.h"

class GameNetProxy final : public NetProxy
{
	MP_SINGLETON_DECLARE(GameNetProxy);
public:
	virtual bool InitServerCfg(const std::string& filename)override;
	virtual void OnClientDisconnect(const uint8_t nType, const MPSOCK nSockIndex)override;
	virtual void OnClientConnected(const uint8_t nType, const MPSOCK nSockIndex)override;
	virtual void LogicStart()override;
	virtual void LogicFinal()override;
	virtual void LogicRun()override;
	virtual const MPGUID GetGUIDBySock(const uint8_t nType,const MPSOCK nSockIndex)const override;
public:
	template<typename T>
	T* GetModule(uint32_t nType)
	{
		return m_Mgrs.GetModule<T>(nType);
	}

	template<typename T>
	const T* GetModule(uint32_t nType)const
	{
		return m_Mgrs.GetModule<T>(nType);
	}

	void SendGameMsgWrapper(
		uint32_t nPlatfromId,
		uint32_t nServerId,
		uint8_t nServerType,
		const uint16_t nMsgId,
		google::protobuf::Message& msg
	);
private:
private:
	ManagerModuleManager m_Mgrs;

	uint32_t m_nPlatformId;
	uint32_t m_nServerId;
};

#define g_pGameNetProxy GameNetProxy::GetInstance()