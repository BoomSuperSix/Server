#pragma once
#include <stdint.h>
#include <memory>
#include "MPGUID.h"

class MatchUser 
{
public:
	MatchUser(double fRating = 1500.0f);
	virtual ~MatchUser();
public:
	double RoundRating(double places);
	double GetRating()const;
	void SetRating(double fRate);
private:
	MPGUID m_uid;
	double m_fRating;
};
typedef std::shared_ptr<MatchUser> MatchUserPtr;