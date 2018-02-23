#pragma once
#include "BattleCommDef.h"

//template<uint32_t x1,uint32_t y1,uint32_t x2,uint32_t y2>
template<uint32_t size>
class PointDistanceCalcT
{
public:
	PointDistanceCalcT() {};
	~PointDistanceCalcT() {};
public:
	enum {
		//Distance = PointDistanceCalcT<size-1>
	};
public:
	static const std::map<uint64_t, uint32_t> m_mDistance;
	static const uint32_t Distance = 0;
};

template<>
class PointDistanceCalcT<0>
{
public:
	enum {
		Distance = 0
	};
};