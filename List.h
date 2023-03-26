#ifndef LIST_H
#define LIST_H
#include "Triangle.h"
#include <iostream>
struct Node {
	Triangle tri;
	Node* next;
	Node* prev;
};
class List {
public:
	Node* head;
	List();
	void DeleteAll();
	int size();
	void AddElem(Triangle tri1);
	void DeleteElem(int i);
	void GetElem(int i);
	~List();
	void insert(int i,Triangle tri);
	friend std::ostream& operator<<(std::ostream& out, List& d);
};
#endif