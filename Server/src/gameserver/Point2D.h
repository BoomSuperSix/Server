#pragma once
#include <stdint.h>

typedef int8_t UNIT_TYPE;

class Point2D
{
public:
	Point2D();
	Point2D(const UNIT_TYPE x,const UNIT_TYPE y);
	Point2D(const Point2D&);
	~Point2D();
public:
	Point2D & operator=(const Point2D&);
	bool operator==(const Point2D&)const;
	bool operator!=(const Point2D&)const;

	Point2D operator+(const Point2D&)const;
	Point2D operator-(const Point2D&)const;
	Point2D operator*(int nRate)const = delete;
	Point2D operator/(const Point2D&)const = delete;

	bool operator<(const Point2D&)const;
	bool operator>(const Point2D&)const;
	bool operator<=(const Point2D&)const;
	bool operator>=(const Point2D&)const;
public:
	void SetPos(const UNIT_TYPE x, const UNIT_TYPE y);
	UNIT_TYPE GetX()const;
	UNIT_TYPE GetY()const;

	void Clear();
private:
	UNIT_TYPE m_x;
	UNIT_TYPE m_y;
};