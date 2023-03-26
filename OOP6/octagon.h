#ifndef OOP_OCTAGON_H
#define OOP_OCTAGON_H

#include "vertex.h"

template <class T>
class Octagon {
public:
    vertex<T> dots[8];

    explicit Octagon<T>(std::istream& is) {
        for (auto& dot : dots) {
            is >> dot;
        }
    }

    Octagon<T>() = default;

    double Area() {
        double area = 0.0;
        int j = 7;

        for (int i = 0; i < 8; i++)

        {

            area += (dots[j].x + dots[i].x) * (dots[j].y - dots[i].y); // (X[j] + X[i])* (Y[j] - Y[i]);

            j = i;  // j - предыдущая вершина i

        }



        // Возвращаем абсолютное значение

        return abs(area / 2.0);

    }
       

    void Printout(std::ostream& os) {
        for (int i = 0; i < 8; ++i) {
            os << this->dots[i];
            if (i != 7) {
                os << ", ";
            }
        }
        os << std::endl;
    }

    void operator<< (std::ostream& os) {
        for (int i = 0; i < 8; ++i) {
            os << this->dots[i];
            if (i != 7) {
                os << ", ";
            }
        }
    }
};

#endif 