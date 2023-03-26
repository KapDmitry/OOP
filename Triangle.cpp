#include "Triangle.h"
#include <cmath>
Triangle::Triangle() {
	Point a(0, 0);
	Point b(0, 0);
	Point c(0, 0);
}
Triangle::Triangle(Point x, Point y, Point z) {
	a = x;
	b = y;
	c = z;
}
std::ostream& operator<<(std::ostream& out, const Triangle& d) {
	out << d.a << "\t" << d.b<<"\t"<<d.c;
	return out;
}
std::istream& operator>>(std::istream& in, Triangle& d) {
	in >> d.a.point_x;
	in >> d.a.point_y;
	in >> d.b.point_x;
	in >> d.b.point_y;
	in >> d.c.point_x;
	in >> d.c.point_y;
	return in;
}
Triangle Triangle::operator=(const Triangle& pnt) {
	a = pnt.a;
	b = pnt.b;
	c = pnt.c;
	return *this;
}
bool Triangle::operator==(Triangle& pnt1) {
	return  ((a == pnt1.a) && (b == pnt1.a) && (c == pnt1.c));
}
Point Triangle::cent() {
	Point result;
	result.point_x = (a.point_x + b.point_x + c.point_x) / 3.;
	result.point_y = (a.point_y + b.point_y + c.point_y) / 3.;
	return result;
}
double Triangle::sq() {
	double s;
	s  = abs(0.5 * (a.point_x * (b.point_y - c.point_y) +b.point_x * (b.point_y - a.point_y) + c.point_x * (a.point_y - b.point_y)));
	return s;
}