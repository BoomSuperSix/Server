#pragma once
#include <memory>
#include "BattleCommDef.h"
#include "BattleInfo.h"

class BattleBase
{
public:
	BattleBase();
	virtual ~BattleBase();
public:
	virtual void ReuseInit();
	virtual bool BattleInit(BATTLE_ID_TYPE id, const BattleInfo& bi);
	virtual bool BattleStart();
	virtual bool BattleRun();
	virtual bool BattleEnd();
	virtual bool BattleErrorEnd();
public:
	BattleStatus GetStatus()const;
	void SetStatus(BattleStatus bs);

	uint32_t GetRound()const;
	void SetRound(uint32_t nRound);
protected:
			
private:
	BattleStatus m_nStatus;
	uint32_t m_nRound;
	uint32_t m_nMaxRound;
	BattleFighterPtr m_pCurActor;
};

typedef std::shared_ptr<BattleBase> BattlePtr;