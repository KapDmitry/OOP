#include "Stack.h"
#include "Romb.h"
#include <memory>
template<typename T>
Stack<T>::Stack() {
	ptr = nullptr;
}
template<typename T>
void Stack<T>::push(T b) {
	std::shared_ptr<Node<T>> ptr1 = std::make_shared<Node<T>>();
	ptr1->rom = b;
	if (ptr == NULL) {
		ptr1->next = NULL;
	}
	else {
		ptr1->next = ptr;
	}
	ptr = ptr1;
	//ptr->next = NULL;
	size++;
}

std::ostream& operator<<(std::ostream& out, const Stack<Romb<int>>& d) {
		std::shared_ptr<Node<Romb<int>>> p = d.ptr;
		while (p != NULL) {
			out << p->rom<<"\n";
			p = p->next;
		}
		//out << "1";

	return out;
}
template<typename T>
T Stack<T>::top() {
	return ptr->rom;
}
template<typename T>
bool Stack<T>::is_empty() {
	if (size!=0) {
		return false;
	}
	else {
		return true;
	}
}
template<typename T>
void Stack<T>::pop() {
	std::shared_ptr<Node<T>> p = ptr->next;
	ptr = p;
	--size;
}
template<typename T>
SIterator<Node<T>> Stack<T>::end() {
	//return ptr;
	SIterator<Node<T>> p;
	p.si = ptr;
	return p;
}
template<typename T>
SIterator<Node<T>> Stack<T>::begin() {
	std::shared_ptr<Node<T>> p = ptr;
	while (p->next != nullptr) {
		p = p->next;
	}
	SIterator<Node<T>> pr;
	pr.si = p;
	return pr;
}
template<typename T>
void Stack<T>::erase(SIterator<Node<T>> it) {
	std::shared_ptr<Node<T>> p = ptr;
	//std::shared_ptr<Node<T>> p1(it.si);
	if (p == it.si) {
		p = ptr->next;
		ptr = p;
		size--;
		}
	else {
		while (p->next != it.si) {
			if (p->next != NULL)
			{
				p = p->next;
			}
			else
			{
				std::cout << "Element didn't find\n";
				break;
			}
		}
		/*std::shared_ptr<Node<T>> p2 = ptr;
		while (p2->next != p) {
			if (p2->next != NULL) {
				p2 = p2->next;
			}
		}
		p2->next = p->next;
		size--;
		p = NULL;
		*/
		p->next = it.si->next;
		size--;
		//it.si = p;
		//it.si = NULL;
	//std::cout << p->rom;
	}
}

template <typename T> 
SIterator<Node<T>> Stack<T>::pos(int a) {
	std::shared_ptr<Node<T>> p = ptr;
	if (a > size) { std::cout << "error\n"; }
	else {
		for (int i = size - a - 1; i > 0; --i) {
			if (p->next != NULL) {
				p = p->next;
			}
			//std::cout << "!\n";
		}
		SIterator<Node<T>> t;
		t.si = p;
		//std::cout << "Pos val = " << t.si->rom << "\n";
		return t;
	}
}
template <typename T>
void Stack<T>::insert(SIterator<Node<T>> it,T b) {
	std::shared_ptr<Node<T>> p = ptr;


	while (p != it.si) {
		if (p->next != NULL)
		{
			p = p->next;
		}
		else
		{
			std::cout << "Element didn't find\n";
			break;
		}
	}
	std::shared_ptr<Node<T>> p1 = std::make_shared<Node<T>>();
	p1->next = p->next;
	p->next = p1;
	p1->rom = b;
	size++;
}
std::ostream& operator<<(std::ostream& out, const Node<Romb<int>>& d) {
	out <<  d;
	//out << "1";

	return out;
}
template <typename T>
T Stack<T>::get_val(SIterator<Node<T>> it) {
	return  it.si->rom;
}
template <typename T>
int Stack<T>::size_of() {
	return size;
}
template class Stack<Romb<int>>;
template class Stack<Romb<double>>;
template class SIterator<Node<Romb<double>>>;
template class SIterator<Node<Romb<int>>>;
