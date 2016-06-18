#include "Point.h"


namespace GuiEngine {

	Point::Point() : x(0), y(0)
	{
	}


	Point::Point(int x, int y) : x(x), y(y)
	{

	}

	Point::~Point()
	{
	}


	int Point::getX()
	{
		return x;
	}
	int Point::getY()
	{
		return y;
	}

	void Point::setX(int newX)
	{
		x = newX;

	}

	void Point::setY(int newY)
	{
		y = newY;
	}
}