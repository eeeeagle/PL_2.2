#include "Point.h"

Point::Point() : _x(0), _y(0), _z(0) {};
Point::Point(double x, double y, double z) : _x(x), _y(y), _z(z) {};

void Point::SetX(double x)
{
	_x = x;
}
void Point::SetY(double y)
{
	_y = y;
}
void Point::SetZ(double z)
{
	_z = z;
}
double Point::GetX() const
{
	return _x;
}
double Point::GetY() const
{
	return _y;
}
double Point::GetZ() const
{
	return _z;
}