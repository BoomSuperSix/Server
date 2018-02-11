#pragma once
#include "BattleCommDef.h"

class AStarPoint
{
public:
	AStarPoint();
	AStarPoint(POS_TYPE& pos);
	~AStarPoint();
	AStarPoint(const AStarPoint&);
	AStarPoint& operator=(const AStarPoint&);

	bool operator==(const AStarPoint&)const;
	bool operator!=(const AStarPoint&)const;
	bool operator<(const AStarPoint&)const;
	bool operator>(const AStarPoint&)const;

public:
	void SetPos(POS_TYPE pos);
	POS_TYPE GetPos()const;

	void SetParent(const AStarPoint* pParent);
	const AStarPoint* GetParent()const;

	void SetF(int v);
	int GetF()const;

	void SetG(int v);
	int GetG()const;

	void SetH(int v);
	int GetH()const;

	void CalcF();

	int GetUniqueId()const;
private:
	POS_TYPE m_Pos;
	const AStarPoint* m_pParent;
	int f;
	int g;
	int h;
};