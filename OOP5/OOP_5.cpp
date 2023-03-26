// Капалин Д.С. М80-201Б-20
// Вариант 5
// Реализовать стэк, содержащий в себе фигуру Ромб


#include "OOP_5.h"
#include "Romb.h"
#include "Stack.h"
#include "MyIteraror.h"
#include <memory>
using namespace std;
template<typename T>
void for_each(SIterator<Node<T>> a, SIterator<Node<T>> b, Stack<T>) {
	while (a.si != b.si) {
		std::cout << a.si->rom << "\n";
		--a;
	}
	std::cout << b.si->rom << "\n";
}
template <typename T>
int count_if(SIterator<Node<T>> a, SIterator<Node<T>> b, Stack<T>, double sq) {
	int c = 0;
	while (a.si != b.si) {
		if (a.si->rom.sq() < sq) {
			c++;
		}
		--a;
	}
	if (b.si->rom.sq() < sq) {
		c++;
	}
	return c;
}

int main()
{
	int c = 0;
	Stack<Romb<int>> s;
	while (1) {
		std::cout << "1.Create stack 2.Push 3.Top 4.Pop 5.Erase 6.Insert 7.Size 8.Empty 9.for_each 10. count_if 11.Exit\n";
		std::cin >> c;
		if (c == 1) {
			Stack<Romb<int>> v;
			s = v;
		}
		if (c == 2) {
			Romb<int> a;
			a.get_Romb();
			s.push(a);
		}
		if (c == 3) {
			std::cout << s.top() << "\n";
		}
		if (c == 4) {
			if (s.is_empty() != true) {
				s.pop();
			}
			else { std::cout << "error stack is empty\n"; }
		}
		if (c == 5) {
			int a;
			std::cout << "Input index of element\n";
			std::cin >> a;
			if (a <= s.size_of()) {
				s.erase(s.pos(a));
			}
			else { std::cout << "error\n"; }
		}
		if (c == 6) {
			int a;
			std::cout << "Input index of element\n";
			std::cin >> a;
			std::cout << "Input figure\n";
			Romb<int> b;
			b.get_Romb();
			s.insert(s.pos(a),b);
		}
		if (c == 7) {
			std::cout << s.size_of() << "\n";
		}
		if (c == 8) {
			if (s.is_empty() == true) {
				std::cout << "Yes\n";
			}
			else
			{
				std::cout << "No\n";
			}
		}
		if (c == 9) {
			for_each(s.end(), s.begin(), s);
		}
		if (c == 10) {
			double v;
			std::cout << "Input square\n";
			std::cin >> v;
			std::cout << count_if(s.end(), s.begin(), s, v);
		}
		if (c == 11) {
			exit(1);
		}
	}

	
	return 0;
}
