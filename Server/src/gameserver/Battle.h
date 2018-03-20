#pragma once

#include <memory>
#include "BattleBase.h"

class BattlePVE : public BattleBase
{
public:
	BattlePVE();
	~BattlePVE();
public:
	virtual bool BattleInit(BATTLE_ID_TYPE id, const BattleInfo& bi)override;
	virtual bool BattleStart()override;
	virtual bool BattleRun()override;
	virtual bool BattleEnd()override;
	virtual bool BattleErrorEnd()override;
public:
private:
	
};
