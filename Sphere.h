#pragma once
#include "Point.h"

class Sphere
{
	double _radius;
	Point _centerOfSphere;
public:
	Sphere();
	Sphere(Point centerOfSphere, double radius);
	void SetRadius(double radius);
	double GetRadius() const;
	void SetCenterOfSphere(Point centerOfSphere);
	Point GetCenterOfSphere() const;
	double Area() const;
	double Volume() const;
	bool PointInsideSphere(const Point& point) const;
	bool IntersectionOfSpheres(const Sphere& a) const;
};