#include<iostream>
#include"Romb.h"
#include"Stack.h"
#include <memory>
#include "MyIteraror.h"
template<typename T>
SIterator<T>::SIterator() {
	si = NULL;
}
template<typename T>
SIterator<T>& SIterator<T>::operator--() {
	si = si->next;
	return *this;
}
template<typename T>
 SIterator<T>::~SIterator() {
	//std::cout<<"destroyed\n";
}


template class SIterator<Node<Romb<double>>>;
template class SIterator<Node<Romb<int>>>;
