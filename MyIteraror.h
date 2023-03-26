#ifndef MYITERATOR_H
#define MYITERATOR_H
#include<iostream>
#include"Romb.h"
#include"Stack.h"
#include <memory>
template< typename T>
class SIterator : public std::iterator<std::input_iterator_tag, T>  {
public:
	std::shared_ptr<T> si;
	SIterator();
	//SIterator();
	SIterator<T>& operator--();
	//Romb<double> operator*();
	~SIterator();
};
#endif MYITERATOR_H