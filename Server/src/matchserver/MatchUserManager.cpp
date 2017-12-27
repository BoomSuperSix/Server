#include "MatchUserManager.h"

MatchUserManager::MatchUserManager() 
	: ManagerModule(eMatchMgr_MatchUser)
	, m_mAllMatchUsers()
	, m_pDistribuiton(std::make_shared<LogisticDistribution>(10,400))
	, m_fK(40)
{

}

MatchUserManager::~MatchUserManager()
{
}

bool MatchUserManager::Awake()
{
	return true;
}

bool MatchUserManager::AfterAwake()
{
	return true;
}

bool MatchUserManager::Execute()
{
	return true;
}

bool MatchUserManager::BeforeShutDown()
{
	return true;
}

bool MatchUserManager::ShutDown()
{
	return true;
}

double MatchUserManager::expectedScore(double fA, double fB)
{
	return 1 - m_pDistribuiton->cdf(fA, fB);
}

double MatchUserManager::CalcRating(double fA, double fB, double fResult)
{
	double expected_sum = 0.0;
	double score_sum = 0.0;

	expected_sum += expectedScore(fA, fB);
	score_sum += fResult;

	return fA + m_fK * (score_sum - expected_sum);
}