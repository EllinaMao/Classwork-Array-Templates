#pragma once
#include <iostream>
using namespace std;

class Point     /////// це приклад ООП ,маємо клас з інкапсульованими полями int x;	int y; та public інтерфейсом
{
private:
	int x;
	int y;
public:
	Point(); // construct by default
	Point(int x1, int y1); // Construct by 2 param
	Point(const Point& pnt); // Construct by 2 param

	void Init(int x1, int y1);///перегрузка фнкции Init
	void Output() const;
	void Sum(const Point& p); //////можу передати const Point pnt1;  a можу передати  Point pnt2;


	void SetX(int xx);// сеттер
	int GetX() const;//геттер
	void SetY(int yy);// сеттер
	int GetY() const;//геттер

};