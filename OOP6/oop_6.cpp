//Капалин Д.С. М80-201Б-20
//Вариант 8
// Фигура - 8-ми угольник
// Контейнер - стэк
// контейнер аллокатора - очередь

#
#
#include <iostream>
#include <algorithm>
#include "octagon.h"

#include "containers/stack.h"
#include "allocator.h"

int main() {
    size_t N;
    float S;
    int option = '0';
    containers::stack<Octagon<int>, allocators::my_allocator<Octagon<int>, 800>> q;
    Octagon<int> rect{};
    while (1) {
            std::cout << "1) push new element in stack\n"
                << "2) insert element by positon\n"
                << "3) pop \n"
                << "4) delete element by position\n"
                << "5) print stack\n"
                << "6) count if\n"
                << "7) exit\n" << std::endl;
            std::cin >> option;
        if(option == 1) {
            std::cout << "enter ocatagon using radius and center coordinates : " << std::endl;
            int r;
            int px;
            int py;
            std::cout << "radius\n";
            std::cin >> r;
            std::cout << "point center\n";
            std::cin >> px >> py;
            int t = 45;
            Octagon<int>rect;
            for (int i = 1; i < 9; i++) {
                rect.dots[i - 1].x = round(px + r * cos(i*3.14/4));
                rect.dots[i - 1].y = round(py + r * sin(i * 3.14 / 4));
                t = t + 45;
            }
            q.push(rect);
        }
        if (option==2) {
            std::cout << "enter position to insert to: ";
            std::cin >> N;
            std::cout << "enter ocatagon using radius and center coordinates :";
            int r;
            int px;
            int py;
            std::cout << "radius\n";
            std::cin >> r;
            std::cout << "point center\n";
            std::cin >> px >> py;
            int t = 0;
            Octagon<int>rect;
            for (int i = 1; i < 9; i++) {
                rect.dots[i - 1].x = round(px + r * cos(i * 3.14 / 4));
                rect.dots[i - 1].y = round(py + r * sin(i * 3.14 / 4));
                t = t + 45;
            }
            q.insert_by_number(N, rect);
        }
        if (option == 3) {
            q.pop();
        }
        if(option==4) {
            std::cout << "enter position to delete: ";
            std::cin >> N;
            q.delete_by_number(N);
        }
        if(option==5) {
            std::for_each(q.begin(), q.end(), [](Octagon<int>& X) { X.Printout(std::cout); });
        }
        if (option==6) {
            std::cout << "enter max area to search to: ";
            std::cin >> S;
            std::cout << "number of elements with value less than " << S << " is " << std::count_if(q.begin(), q.end(), [=](Octagon<int>& X) {return X.Area() < S; }) << std::endl;
        }
        if (option == 7) {
            exit(1);
        }
    }
    return 0;
}