#include "Romb.h"
#include <cmath>
#include <iostream>
template<typename T>
Romb<T>::Romb() {
	for (int i = 0; i < 4; i++) {
		pts[i].first = 0;
		pts[i].second = 0;
	}
}
template<typename T>
double Romb<T>::sq() {
	double result = 0;
	double d1 = sqrt((pts[2].first - pts[0].first) * (pts[2].first - pts[0].first) + (pts[2].second - pts[0].second) * (pts[2].second - pts[0].second));
	double d2 = sqrt((pts[3].first - pts[1].first) * (pts[3].first - pts[1].first) + (pts[3].second - pts[1].second) * (pts[3].second - pts[1].second));
	result = 1. / 2 * d1 * d2;
	return result;
}

std::ostream& operator<<(std::ostream& out, const Romb<int>& d) {
	for (int i = 0; i < 4; i++) {
		out << d.pts[i].first << "\t" << d.pts[i].second << "\t";
		//out << "1";
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const Romb<double>& d) {
	for (int i = 0; i < 4; i++) {
		out << d.pts[i].first << "\t" << d.pts[i].second << "\t";
		//out << "1";
	}
	return out;
}
template<typename T>
void Romb<T>::get_Romb() {
	int c = 0;
	while(c == 0) {
		for (int i = 0; i < 4; i++) {
			std::cin >> pts[i].first >> pts[i].second;
		}
		//c = c + 1;
		int a = 0;
		for (int i = 0; i < 4; i++) {
			if (pts[i].first == 0) {
				a = a + 1;
			}
			if (pts[i].second == 0) {
				a = a + 1;
			}
		}
		if (a <= 4) {
			double d = abs((pts[2].first - pts[0].first) * (pts[3].first - pts[1].first) + (pts[2].second - pts[0].second) * (pts[3].second - pts[1].second));
			if (d == 0) {
				c++;
			}
			else { std::cout << "Error redo input\n"; }
		}
		else { std::cout << "Error redo input\n"; }
		//std::cout << c;
	}
}
template class Romb<int>;
template class Romb<double>;
