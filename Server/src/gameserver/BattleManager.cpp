#include "BattleManager.h"
#include "MPLogger.h"

MP_SINGLETON_IMPLEMENT(BattleManager)

BattleManager::BattleManager() : meplay::MPThread("BattleThread")
{
}

BattleManager::~BattleManager()
{
}

void BattleManager::Run()
{
	while (!IsThreadFinal())
	{
		m_tLastTime.Now();
		UpdateBattle();
		auto millisec = m_tLastTime.MTimeOut(100);
		if (millisec < 0)
		{
			MP_WARN("BattleLoop TimeOut %d", -millisec);
			millisec = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(millisec));
	}
}

void BattleManager::UpdateBattle()
{
	addBattle();

	delBattle();

	updateBattle();
}

BATTLE_ID_TYPE BattleManager::AddBattle(const BattleInfo& bi)
{
	auto pBattle = m_BattleFactory.CreateBattle((BATTLE_TYPE)bi.nBattleType);
	if (pBattle == nullptr)
	{
		MP_INFO("AddBattle Failed!");
		return INVALID_BATTLE_ID;
	}

	auto lBattleId = createBattleId();

	if (!pBattle->BattleInit(lBattleId, bi))
	{
		MP_INFO("AddBattle Failed!");
		return INVALID_BATTLE_ID;
	}

	std::lock_guard<std::mutex> lck(mtx);
	m_vAddCache.emplace_back(std::make_pair(lBattleId,pBattle));
	MP_INFO("AddBattle Success!");

	return lBattleId;
}

void BattleManager::DelBattle(BATTLE_ID_TYPE id)
{
	std::lock_guard<std::mutex> lck(mtx);
	m_vDelCache.emplace_back(id);
}

BATTLE_ID_TYPE BattleManager::createBattleId()
{
	return 1;
}

void BattleManager::addBattle()
{
	for (auto& add : m_vAddCache)
	{
		m_mBattleMap.emplace(add);
	}
	mtx.try_lock();
	m_vAddCache.clear();
	mtx.unlock();
}

void BattleManager::delBattle()
{
	for (auto& del : m_vDelCache)
	{
		m_mBattleMap.erase(del);
	}
	mtx.try_lock();
	m_vDelCache.clear();
	mtx.unlock();

	auto it = m_mBattleMap.begin();
	while (it != m_mBattleMap.end())
	{
		auto pBattle = it->second;
		if (pBattle->GetStatus() == eBattleStatus_End
			|| pBattle->GetStatus() == eBattleStatus_ErrorEnd)
		{
			it = m_mBattleMap.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void BattleManager::updateBattle()
{
	for (auto& bi : m_mBattleMap)
	{
		auto& pBattle = bi.second;
		switch (pBattle->GetStatus())
		{
		case eBattleStatus_Start:
		{
			if (!pBattle->BattleStart())
			{
				//error
				pBattle->SetStatus(eBattleStatus_ErrorEnd);
			}
			else
			{
				pBattle->SetStatus(eBattleStatus_Run);
			}
		}
		break;
		case eBattleStatus_Run:
		{
			if (!pBattle->BattleRun())
			{
				//error
				pBattle->SetStatus(eBattleStatus_ErrorEnd);
			}
			else
			{
				pBattle->SetStatus(eBattleStatus_Run);
			}
		}
		break;
		case eBattleStatus_End:
		{
			if (!pBattle->BattleEnd())
			{
				//error
				pBattle->SetStatus(eBattleStatus_ErrorEnd);
			}
			else
			{
				pBattle->SetStatus(eBattleStatus_Run);
			}
		}
		break;
		case eBattleStatus_ErrorEnd:
		{
			pBattle->BattleErrorEnd();
		}
		case eBattleStatus_Unknown:
		case eBattleStatus_Init:
		default:
			break;
		}
	}

}