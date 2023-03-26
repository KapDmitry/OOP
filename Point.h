#ifndef POINT_H
#define POINT_H
#include <iostream>
class Point {
public:
	double point_x;
	double point_y;
	Point();
	Point(double x, double y);
	friend std::ostream& operator<<(std::ostream& out, const Point& d);
	friend std::istream& operator>>(std::istream& in, Point& d);
	Point operator=(const Point& pnt);
	bool operator==( Point& pnt);
};
#endif // !Point
