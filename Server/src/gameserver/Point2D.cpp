#include "Point2D.h"
Point2D::Point2D() 
	: m_x(0),m_y(0)
{
}

Point2D::Point2D(const UNIT_TYPE x, const UNIT_TYPE y)
	: m_x(x),m_y(y)
{
}
Point2D::Point2D(const Point2D& rhs)
{
	if (&rhs == this)
	{
		return;
	}
	*this = rhs;
}

Point2D::~Point2D()
{
}

Point2D& Point2D::operator=(const Point2D& rhs)
{
	m_x = rhs.m_x;
	m_y = rhs.m_y;
	return *this;
}

bool Point2D::operator==(const Point2D& rhs)const
{
	return (m_x == rhs.m_x) && (m_y == rhs.m_y);
}

bool Point2D::operator!=(const Point2D& rhs)const
{
	return !(*this == rhs);
}

Point2D Point2D::operator+(const Point2D& rhs)const
{
	return Point2D(m_x + rhs.m_x, m_y + rhs.m_y);
}

Point2D Point2D::operator-(const Point2D& rhs)const
{
	return Point2D(m_x - rhs.m_x, m_y - rhs.m_y);
}

bool Point2D::operator<(const Point2D& rhs)const
{
	return m_x < rhs.m_x ? true : m_y < rhs.m_y;
}

bool Point2D::operator>(const Point2D& rhs)const
{
	return !(*this < rhs);
}

bool Point2D::operator<=(const Point2D& rhs)const
{
	return m_x <= rhs.m_x ? true : m_y <= rhs.m_y;
}

bool Point2D::operator>=(const Point2D& rhs)const
{
	return !(*this <= rhs);
}

void Point2D::SetPos(const UNIT_TYPE x, const UNIT_TYPE y)
{
	m_x = x;
	m_y = y;
}

UNIT_TYPE Point2D::GetX()const
{
	return m_x;
}
UNIT_TYPE Point2D::GetY()const
{
	return m_y;
}
void Point2D::Clear()
{
	m_x = 0;
	m_y = 0;
}