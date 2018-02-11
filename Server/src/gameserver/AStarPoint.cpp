#include "AStarPoint.h"
#include "GameCommDef.h"

AStarPoint::AStarPoint()
	: m_Pos()
	, m_pParent(nullptr)
	, f(0)
	, g(0)
	, h(0)
{
}

AStarPoint::AStarPoint(POS_TYPE& pos)
	: m_Pos(pos)
	, m_pParent(nullptr)
	, f(0)
	, g(0)
	, h(0)
{
}

AStarPoint::~AStarPoint()
{
}

AStarPoint::AStarPoint(const AStarPoint& rhs)
{
	if (this == &rhs)
	{
		return;
	}
	*this = rhs;
}

AStarPoint& AStarPoint::operator=(const AStarPoint& rhs)
{
	m_Pos = rhs.m_Pos;
	m_pParent = rhs.m_pParent;
	f = rhs.f;
	g = rhs.g;
	h = rhs.h;
	return *this;
}

bool AStarPoint::operator==(const AStarPoint& rhs)const
{
	return m_Pos == rhs.m_Pos;
}

bool AStarPoint::operator!=(const AStarPoint& rhs)const
{
	return m_Pos != rhs.m_Pos;
}

bool AStarPoint::operator<(const AStarPoint& rhs)const
{
	return f < rhs.f;
}

bool AStarPoint::operator>(const AStarPoint& rhs)const
{
	return f > rhs.f;
}


void AStarPoint::SetPos(POS_TYPE pos)
{
	m_Pos = pos; 
}

POS_TYPE AStarPoint::GetPos()const 
{ 
	return m_Pos; 
}

void AStarPoint::SetParent(const AStarPoint* pParent)
{
	m_pParent = pParent; 
}

const AStarPoint* AStarPoint::GetParent()const
{ 
	return m_pParent; 
}

void AStarPoint::SetF(int v) 
{ 
	f = v; 
}

int AStarPoint::GetF()const 
{ 
	return f; 
}

void AStarPoint::SetG(int v)
{ 
	g = v; 
}

int AStarPoint::GetG()const 
{ 
	return g; 
}

void AStarPoint::SetH(int v) 
{ 
	h = v; 
}

int AStarPoint::GetH()const
{ 
	return h; 
}

void AStarPoint::CalcF()
{
	f = g + h;
}

int AStarPoint::GetUniqueId()const
{
	return MAKE_INT_32(m_Pos.GetX(), m_Pos.GetY());
}