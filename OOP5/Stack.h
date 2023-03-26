#ifndef STACK_H
#define STACK_H
#include<iostream>
#include"Romb.h"
#include <memory>
#include "MyIteraror.h"
template<typename T>
struct Node {
	T rom;
	std::shared_ptr<Node<T>> next;
};
template<typename T>
class Stack {
public:
	std::shared_ptr<Node<T>> ptr;
	int size=0;
	Stack();
	void push(T);
	friend std::ostream& operator<<(std::ostream& out, const Stack<T>& d);
	T top();
	bool is_empty();
	void pop();
	SIterator<Node<T>> begin();
    SIterator<Node<T>> end();
	void erase(SIterator<Node<T>> it);
	void insert(SIterator<Node<T>> it, T);
	T get_val(SIterator<Node<T>> it);
	SIterator<Node<T>> pos(int a);
	int size_of();
	//top();
	//Stack* begin();
	//Stack* end();
};
#endif