
#include "Point.h"
Point::Point() {
	point_x = 0.;
	point_y = 0.;
}
Point::Point(double x, double y) {
	point_x = x;
	point_y = y;
}
std::ostream& operator<<(std::ostream& out, const Point& d) {
	out << d.point_x << " " << d.point_y;
	return out;
}
std::istream& operator>>(std::istream& in, Point& d) {
	in >> d.point_x;
	in >> d.point_y;
	return in;
}
Point Point::operator=(const Point& pnt) {
	point_x = pnt.point_x;
	point_y = pnt.point_y;
	return *this;
}
bool  Point::operator==(Point& pnt1) {
	return ((pnt1.point_x == point_x) && (pnt1.point_y == point_y));
}