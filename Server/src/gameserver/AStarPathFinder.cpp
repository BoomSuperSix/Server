#include "AStarPathFinder.h"
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "MPLogger.h"

AStarPathFinder::AStarPathFinder(CHECK_FUNC_TYPE f)
	: m_FuncCheckPosValid(f)
{
}

AStarPathFinder::~AStarPathFinder()
{
}

bool AStarPathFinder::FindPath(const POS_VEC& vBody, POS_TYPE& start, POS_TYPE& end, POS_VEC& vPath)
{
	m_StartPoint = start;
	m_EndPoint = end;
	if (m_StartPoint == m_EndPoint)
	{
		return true;
	}

	AStarPoint startPoint(m_StartPoint);
	AStarPoint endPoint(m_EndPoint);
	addToOpenList(startPoint);
	while (!m_mOpenList.empty())
	{
		auto pMinPoint = calcMinPoint();
		if (pMinPoint == nullptr)
		{
			//未找到Path
			calcClosestPath(endPoint, vPath);
			return false;
		}
		/*std::cout << "MinPoint" << (int)pMinPoint->GetPos().GetX() << "," << (int)pMinPoint->GetPos().GetY() << "."
			<< pMinPoint->GetF() << "," << pMinPoint->GetG() << "," << pMinPoint->GetH() << std::endl;*/
		
		auto vSurroundPoints = calcSurroundPoints(vBody, *pMinPoint);
		for (auto& surround : vSurroundPoints)
		{
			if (isInOpenList(surround))
			{
				foundPoint(*pMinPoint, surround);
			}
			else
			{
				notFoundPoint(*pMinPoint, m_EndPoint, surround);
			}
		}

		if (isInOpenList(endPoint))
		{
			return finishPath(endPoint, vPath);
		}
	}

	return finishPath(endPoint, vPath);
}

bool AStarPathFinder::isPosValid(const POS_VEC& vPos)const
{
	for (auto& pos : vPos)
	{
		if (!isPosValid(pos))
		{
			return false;
		}
	}
	return true;
}

bool AStarPathFinder::isPosValid(const POS_TYPE& pos)const
{
	return m_FuncCheckPosValid(pos);
}

const AStarPoint* AStarPathFinder::calcMinPoint()
{
	static auto AStarComp = []
	(const std::pair<uint32_t, AStarPoint>& it1, const std::pair<uint32_t, AStarPoint> it2)->bool
	{
		return it1.second.GetF() < it2.second.GetF();
	};
	auto itOpenMin = std::min_element(m_mOpenList.begin(), m_mOpenList.end(),AStarComp);
	while (m_mCloseList.find(itOpenMin->first) != m_mCloseList.end())
	{
		//找到了这个点
		m_mOpenList.erase(itOpenMin);
		if (m_mOpenList.empty())
		{
			return nullptr;
		}

		itOpenMin = std::min_element(m_mOpenList.begin(), m_mOpenList.end(), AStarComp);
	}

	//加入closelist
	auto itMinPoint = m_mCloseList.emplace(*itOpenMin).first;
	itOpenMin = m_mOpenList.erase(itOpenMin);
	//返回minpoint
	return &(itMinPoint->second);
}

std::vector<AStarPoint> AStarPathFinder::calcSurroundPoints(const POS_VEC& vBody, const AStarPoint& point)
{
	std::vector<AStarPoint> vRet;
	for (int i = 0; i < SURROUND_SLOT_NUM; ++i)
	{
		//获得周围的点
		auto pos = point.GetPos() + SURROUND_SHIFT[i];
		auto surround = AStarPoint(pos);
		//设置权重
		surround.SetG(SURROUND_WEIGHT[i]);
		bool bValid(true);
		for (auto body_pos : vBody)
		{
			if (isPosValid(surround.GetPos() + body_pos))
			{
				continue;
			}
			bValid = false;
			surround.SetG(INVALID_WEIGHT);
			break;
		}
		if (isPosValid(surround.GetPos()))
		{
			vRet.emplace_back(surround);
		}
	}
	return vRet;
}

void AStarPathFinder::foundPoint(const AStarPoint& startPoint, AStarPoint& point)
{
	auto g = calcG(startPoint, point);
	if (g < point.GetG())
	{
		point.SetParent(&startPoint);
		point.SetG(g);
		point.CalcF();
	}
}

void AStarPathFinder::notFoundPoint(const AStarPoint& startPoint, const AStarPoint& endPoint, AStarPoint& point)
{
	point.SetParent(&startPoint);
	point.SetG(calcG(startPoint, point));
	point.SetH(calcH(m_EndPoint, point));
	point.CalcF();
	addToOpenList(point);
}

int AStarPathFinder::calcG(const AStarPoint& startPoint, const AStarPoint& point)const
{
	int g = point.GetG();
	int parentg = point.GetParent() != nullptr ? point.GetParent()->GetG() : 0;
	return g + parentg;
}

int AStarPathFinder::calcH(POS_TYPE nPos, const AStarPoint& point)const
{
	auto nDisX = std::fabs(nPos.GetX() - point.GetPos().GetX()) * BASE_WEIGHT;
	auto nDisY = std::fabs(nPos.GetY() - point.GetPos().GetY()) * BASE_WEIGHT;
	return std::sqrt(nDisX * nDisX + nDisY * nDisY);
}

bool AStarPathFinder::finishPath(AStarPoint& pt, POS_VEC& vPath)
{
	if (auto it = m_mOpenList.find(pt.GetUniqueId()); it != m_mOpenList.end())
	{
		auto cur_point = it->second;
		bool bHasPath = cur_point.GetG() < INVALID_WEIGHT;
		vPath.emplace_back(cur_point.GetPos());

		while (cur_point.GetParent() != nullptr)
		{
			cur_point = *(cur_point.GetParent());
			vPath.emplace_back(cur_point.GetPos());
		}
		std::reverse(vPath.begin(), vPath.end());

		return bHasPath;
	}
	return false;
}

void AStarPathFinder::calcClosestPath(AStarPoint& pt, POS_VEC& vPath)
{
	static auto CloseComp = []
	(const std::pair<uint32_t, AStarPoint>& it1, const std::pair<uint32_t, AStarPoint> it2)->bool
	{
		auto h1 = it1.second.GetH();
		auto h2 = it2.second.GetH();
		if (h1 == 0)
		{
			return false;
		}
		if (h2 == 0)
		{
			return true;
		}
		return h1 < h2 ? true : h1 == h2 ? it1.second.GetF() < it2.second.GetF() : false;
	};
	for (auto& close_info : m_mCloseList)
	{
		auto& close = close_info.second;
		std::cout << "pos" << (int)close.GetPos().GetX() << "," << (int)close.GetPos().GetY()
			<< "|" << close.GetF() << "," << close.GetG() << "," << close.GetH() << std::endl;
	}
	auto itMin = std::min_element(m_mCloseList.begin(), m_mCloseList.end(),CloseComp);
	//auto itMin = std::min_element(m_mOpenList.begin(), m_mOpenList.end(),CloseComp);
	auto cur_point = itMin->second;
	while (cur_point.GetParent() != nullptr)
	{
		cur_point = *(cur_point.GetParent());
		vPath.emplace_back(cur_point.GetPos());
	}
	std::reverse(vPath.begin(), vPath.end());
}

void AStarPathFinder::addToOpenList(AStarPoint& pt)
{
	m_mOpenList.emplace(pt.GetUniqueId(), pt);
}

bool AStarPathFinder::delFromOpenList(AStarPoint& pt)
{
	return m_mOpenList.erase(pt.GetUniqueId()) > 0;
}

bool AStarPathFinder::isInOpenList(AStarPoint& pt)
{
	return m_mOpenList.find(pt.GetUniqueId()) != m_mOpenList.end();
}

void AStarPathFinder::addToCloseList(AStarPoint& pt)
{
	m_mCloseList.emplace(pt.GetUniqueId(),pt);
}


bool AStarPathFinder::delFromCloseList(AStarPoint& pt)
{
	return m_mCloseList.erase(pt.GetUniqueId()) > 0;
}

bool AStarPathFinder::isInCloseList(AStarPoint& pt)
{
	return m_mCloseList.find(pt.GetUniqueId()) != m_mCloseList.end();
}

//test code！
void AStarPathFinder::TestMe()
{
	std::vector<POS_TYPE> vBlocks
	{
		//POS_TYPE(0,0),
		POS_TYPE(1,1),
		POS_TYPE(2,2),
		POS_TYPE(3,3),
		POS_TYPE(4,4),
		POS_TYPE(5,5),
		//POS_TYPE(1,0),
		POS_TYPE(2,1),
		POS_TYPE(3,2),
		POS_TYPE(4,3),
		POS_TYPE(5,4)
	};
#define MAX_EDGE 5 
	AStarPathFinder finder(
		[vBlocks](const POS_TYPE pos)->bool
	{
		if (pos.GetX() < 0 || pos.GetX() > MAX_EDGE || pos.GetY() < 0 || pos.GetY() > MAX_EDGE)
		{
			return false;
		}

		for (auto& block : vBlocks)
		{
			if (pos.GetX() == block.GetX() && pos.GetY() == block.GetY())
			{
				return false;
			}
		}
		return true;
	}
	);
	POS_TYPE start(MAX_EDGE, 0);
	POS_TYPE end(0, MAX_EDGE);
	POS_VEC vPath;
	bool bFind = finder.FindPath(POS_VEC{ POS_TYPE(0,0) }, start, end, vPath);
	MP_DEBUG("Path Result : %d.", bFind);
	std::stringstream ss;
	for (auto path : vPath)
	{
		MP_DEBUG("Path Is: %d,%d.", path.GetX(), path.GetY());
	}

	std::cout << "-----------------------------------------------" << std::endl;

	for (int y = 0; y <= MAX_EDGE; ++y)
	{
		std::cout << "|";
		for (int x = 0; x <= MAX_EDGE; ++x)
		{
			bool bBlock(false);
			for (auto& block : vBlocks)
			{
				if (x == block.GetX() && y == block.GetY())
				{
					bBlock = true;
					break;
				}
			}
			if (bBlock)
			{
				std::cout << "X";
				std::cout << "|";
			}
			else
			{
				bool bFind(false);
				for (auto pt : vPath)
				{
					if (pt.GetX() == x && pt.GetY() == y)
					{
						bFind = true;
						break;
					}
				}

				std::cout << bFind ? "1" : "0";
				std::cout << "|";
			}
		}
		std::cout << "\n";
	}

	getchar();
}
