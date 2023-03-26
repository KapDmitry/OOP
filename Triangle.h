#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
class Triangle {
public:
	Point a;
	Point b;
	Point c;
	Triangle();
	Triangle(Point x, Point y, Point z);
	Triangle operator=(const Triangle& t);
	double sq();
	Point cent();
	friend std::ostream& operator<<(std::ostream& out, const Triangle& d);
	friend std::istream& operator>>(std::istream& in, Triangle& d);
	bool operator==( Triangle& d1);
};
#endif 