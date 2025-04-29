#include "Point.h"


Point::Point()////це метод класу Point
{
	cout << "Construct 0 param\n";
	x = 0;
	y = 0;
}

Point::Point(int x1, int y1)
{
	cout << "Construct by 2 param\n";
	x = x1;
	y = y1;
}

Point::Point(const Point& pnt)
{
	x = pnt.x;
	y = pnt.y;


}

void Point::Init(int x1, int y1)
{
	x = x1;
	y = y1;
}

void Point::Output() const
{
	cout << "X: " << x << "\tY: " << y << endl;
}

void Point::Sum(const Point& p)
{

	x += p.x;////p відкритий на читання бо const Point&
	y += p.y;
}

void Point::SetX(int xx)
{
	x = xx;
}

int Point::GetX() const
{
	return x;
}

void Point::SetY(int yy)
{
	y = yy;
}

int Point::GetY() const
{
	return y;
}
