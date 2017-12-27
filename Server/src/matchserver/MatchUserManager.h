#pragma once
#include "MatchCommDef.h"
#include "ManagerModule.h"
#include "MatchUser.h"
#include "MatchUserDistribution.h"

class MatchUserManager : public ManagerModule
{
public:
	MatchUserManager();
	~MatchUserManager();
public:
	virtual bool Awake()override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutDown()override;
	virtual bool ShutDown()override;
public:
	//elo calculation
	double CalcRating(double fA, double fB, double fResult);
private:
	//elo
	double expectedScore(double fA, double fB);
private:
	std::unordered_map<MPGUID,MatchUserPtr> m_mAllMatchUsers;

	std::shared_ptr<Distribution> m_pDistribuiton;

	double m_fK;
};

MATCH_MANAGER_MODULE_REG(eMatchMgr_MatchUser, MatchUserManager);