#pragma once
#include <functional>
#include <set>
#include <list>
#include "AStarPoint.h"

typedef std::function<bool(const POS_TYPE)> CHECK_FUNC_TYPE;

struct AStarPointCmp
{
	bool operator()(const AStarPoint& lhs, const AStarPoint& rhs) const
	{
		return lhs < rhs;
	}
};

class AStarPathFinder
{
public:
	AStarPathFinder(CHECK_FUNC_TYPE f);
	~AStarPathFinder();
public:
	bool FindPath(const POS_VEC& vMe,POS_TYPE& start,POS_TYPE& end, POS_VEC& vPath);
	void TestMe();
private:
	bool isPosValid(const POS_VEC& vPos)const;
	bool isPosValid(const POS_TYPE& pos)const;
	//计算出F值最小的一个点
	const AStarPoint* calcMinPoint();
	std::vector<AStarPoint> calcSurroundPoints(const POS_VEC& vBody, const AStarPoint& point);//支持多格单位

	void foundPoint(const AStarPoint& startPoint, AStarPoint& point);
	void notFoundPoint(const AStarPoint& startPoint, const AStarPoint& endPoint, AStarPoint& point);
	int calcG(const AStarPoint& startPoint, const AStarPoint& point)const;
	int calcH(POS_TYPE pos, const AStarPoint& point)const;
	bool finishPath(AStarPoint& pt, POS_VEC& vPath);
	void calcClosestPath(AStarPoint& pt, POS_VEC& vPath);

	void addToOpenList(AStarPoint& pt);
	bool delFromOpenList(AStarPoint& pt);
	bool isInOpenList(AStarPoint& pt);

	void addToCloseList(AStarPoint& pt);
	bool delFromCloseList(AStarPoint& pt);
	bool isInCloseList(AStarPoint& pt);
private:
	CHECK_FUNC_TYPE m_FuncCheckPosValid;
	POS_TYPE m_StartPoint;
	POS_TYPE m_EndPoint;
	std::map<uint32_t,AStarPoint> m_mOpenList;
	std::map<uint32_t,AStarPoint> m_mCloseList;
};