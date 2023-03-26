//Капалин Д.С, М80-201Б-20
// Лабораторная 4
//Класс-контейнер список
// Вариант 12
// фиугра треугольник
#include "OOP4.h"
#include "Point.h"
#include "Triangle.h"
#include "List.h"
#include <vector>
#include <iostream>
//using namespace std;
int main()
{
	List l;
	int c = 0;
	while (1) {
		std::cout << "1. Create list 2.Push back 3.insert 4.Delete 5.Print 6.Delete all 7.Size  8.Exit"<< "\n";
		std::cin >> c;
		if (c == 1) {
			List l();
		}
		if (c == 2) {
			Triangle tri;
			std::cin >> tri;
			l.AddElem(tri);
		}
		if (c == 3) {
			int i = 0;
			std::cout << "input index of insert\n";
			std::cout << "attention! indexes starts from 1\n";
			std::cin >> i;
			Triangle tri;
			std::cin>> tri;
			l.insert(i, tri);
		}
		if (c == 4) {
			int i = 0;
			std::cout << "input index of insert\n";
			std::cout << "attention! indexes starts from 1\n";
			std::cin >> i;
			l.DeleteElem(i);
		}
		if (c == 5) {
			std::cout << l;
		}
		if (c == 6) {
			l.DeleteAll();
		}
		if (c == 7) {
			std::cout << l.size() << "\n";
		}
		if (c == 8) {
			exit(1);
		}
	}
	return 0;
}
