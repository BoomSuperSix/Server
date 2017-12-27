#include "MatchUser.h"

MatchUser::MatchUser(double fRating) 
	: m_uid(),m_fRating(fRating)
{
}

MatchUser::~MatchUser()
{
}

double MatchUser::RoundRating(double places)
{
	if (m_fRating == 0)
	{
		return 0;
	}

	double scale = std::pow(10.0, places);
	return std::round(m_fRating * scale) / scale;
}

double MatchUser::GetRating()const
{
	return m_fRating;
}

void MatchUser::SetRating(double fRate)
{
	m_fRating = fRate;
}