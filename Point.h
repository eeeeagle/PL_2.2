class Point
{ 
	double _x, _y, _z;
public:
	Point();
	Point(double x, double y, double z);
	void SetX(double value);
	void SetY(double value);
	void SetZ(double value);
	double GetX() const;
	double GetY() const;
	double GetZ() const;
};