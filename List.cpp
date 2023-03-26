//Капалин Д.С, М80-201Б-20
// Лабораторная 4
//Класс-контейнер список
// Вариант 12
// фиугра треугольник
#include "Triangle.h"
#include "Point.h"
#include "List.h"
#include <cmath>
#include <iostream>

List::List() {
	head = NULL;
}
void List::AddElem(Triangle tri1) {
	struct Node* elem = (Node*)(malloc(sizeof(struct Node)));
	elem->next = NULL;
	elem->prev = NULL;
	elem->tri=tri1;
	if (head == NULL) {
		head = elem;
	}
	else {
		Node* nx = head;
		nx->next=head->next;
		
			while (nx->next != NULL &&  nx!= NULL) {
				nx = nx->next;
			}
			nx->next = elem;
			elem->prev = nx;
		
	}
	
}
std::ostream& operator<<(std::ostream& out, List& d) {
	if (d.head != NULL) {
		//std::cout << "yeeeee\n";
		struct Node* nx = d.head;
		nx->next = d.head->next;
		while (nx != NULL) {
			out << nx->tri << "\n";
			nx = nx->next;
			//	delete[]nx;
		}
	}
	return out;
}
int List::size() {
	if (head) {
		Node* nx = head;
		int c = 0;
		nx->next = head->next;
		if (nx) {
			while (nx->next != NULL) {
				nx = nx->next;
				++c;
			}
		}
		return c + 1;
	}
	else {
		return 0;
	}
}
void List::DeleteElem(int i) {
	if (i == 1) {
		if (head->next != NULL) {
			Node* h1 = head;
			if (head->next != NULL) {
				head = head->next;
			}
			else { head = NULL; }
			
			free(h1);
		}
		else {
			free(head);
			head = NULL;
		}
	}
	 if (i>1 ){
		Node* nx = head;
		nx->next = head->next;
		nx->prev = NULL;
		//std::cout << nx->next->tri;
		int c = 0;
		if (nx) {
			while ((nx->next != NULL || i < c + 1 )&& nx!=NULL) {
				nx = nx->next;
				c = c + 1;
				if (c == i - 1) {
					break;
				}
			}
			//std::cout << nx->tri;
			if (c == i - 1) {
				Node* t = nx->prev;
				Node* m;
				if (nx->next != NULL) {
					m = nx->next;
				}
				else { m = NULL; }
				t->next = m;
				if (m != NULL) {
					m->prev = t;
				}
				free(nx);
			}
		}
	 }
}
void List::GetElem(int a) {
	if (a == 1) {
		std::cout << head->tri;
	}
	if (a > 1) {
		Node* nx = head;
		nx->next = head->next;
		nx->prev = NULL;
		for (int i = 0; i < a; i++) {
			if (nx != NULL && nx->next != NULL) {
				nx = nx->next;
			}
		}
		std::cout << nx->tri;

	}
}
void List::insert(int i, Triangle tri1) {
	Node* elem = (Node*)(malloc(sizeof(Node)));
	elem->tri = tri1;
	elem->next = NULL;
	elem->prev = NULL;
	if (i == 1) {
		Node* t = head;
		head = elem;
		elem->next = t;
	}
	if (i > 1) {
		Node* nx = head;
		nx->next = head->next;
		nx->prev = NULL;
		for (int c = 0; c < i; c++) {
			if (nx != NULL && nx->next != NULL) {
				nx = nx->next;
			}
		}
		Node* k = nx->prev;
		std::cout << nx->tri;
		k->next = elem;
		elem->prev = k;
		elem->next = nx;
		nx->prev = elem;

	}
}

List::~List() {
	if (head) {
		Node* nx = head;
		nx->next = head->next;
		nx->prev = NULL;
		if (nx != NULL) {
			while (nx->next != NULL) {
				Node* t = nx;
				nx = nx->next;
				free(t);
			}
		}
	}
}
void List::DeleteAll() {
	if (head) {
		Node* t = head;
		Node* nx=NULL;
		if (head->next) {
			Node* nx = head->next;
		}
		if (nx) {
			nx->prev = NULL;
		}
		if (nx != NULL) {
			while (nx->next != NULL) {
				Node* m = nx;
				nx = nx->next;
				free(m);
			}
		}
		free(t);
		head = NULL;
	}
}