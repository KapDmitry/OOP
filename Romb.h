#ifndef ROMB_H
#define ROMB_H
#include<iostream>
template<typename T>
class Romb {
public:
	std::pair<T, T> pts[4];
	 Romb();
	void get_Romb();
	double sq();
	friend std::ostream& operator<<(std::ostream& out, const Romb<T>& d);
	
};
#endif