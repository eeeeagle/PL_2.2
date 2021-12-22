#define _USE_MATH_DEFINES
#include "Sphere.h"
#include <cmath>
#define PI M_PI

Sphere::Sphere() : _centerOfSphere(0, 0, 0), _radius(1) {};
Sphere::Sphere(Point centerOfSphere, double radius) : _centerOfSphere(centerOfSphere), _radius(radius) {};

void Sphere::SetRadius(double radius)
{
	if (radius > 0)
		_radius = radius;
}

double Sphere::GetRadius() const
{
	return _radius;
}

void Sphere::SetCenterOfSphere(Point CenterOfSphere)
{
	_centerOfSphere = CenterOfSphere;
}

Point Sphere::GetCenterOfSphere() const
{
	return _centerOfSphere;
}

double Sphere::Area() const
{
	return (4.0 * PI * _radius * _radius);
}

double Sphere::Volume() const
{
	return (4.0  * PI / 3.0 * _radius * _radius * _radius);
}

bool Sphere::PointInsideSphere(const Point& point) const
{
	double tempX = point.GetX() - _centerOfSphere.GetX();
	double tempY = point.GetY() - _centerOfSphere.GetY();
	double tempZ = point.GetZ() - _centerOfSphere.GetZ();
	double distance = sqrt(tempX * tempX + tempY * tempY + tempZ * tempZ);
	return (distance < _radius);
}

bool Sphere::IntersectionOfSpheres(const Sphere& a) const
{
	double tempX = _centerOfSphere.GetX() - a._centerOfSphere.GetX();
	double tempY = _centerOfSphere.GetY() - a._centerOfSphere.GetY();
	double tempZ = _centerOfSphere.GetZ() - a._centerOfSphere.GetZ();
	double distance = sqrt(tempX * tempX + tempY * tempY + tempZ * tempZ);
	return (distance <=  (_radius + a._radius));
}