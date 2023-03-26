#pragma once
#include <memory>
#include <algorithm>
#include <string>
#include <math.h>
#include "pentagon.hpp"
#include "rhomb.hpp"
#include "trapeze.hpp"
#include "figure.hpp"
using namespace std;
template<class T, class Figure>
class Factory;

template<class T>
class Factory< T, Rhomb<T> > {
public:
    static shared_ptr<Figure<T>> CreateFigure(istream& in) {
        vector<pair<T, T>> points(4);
        try
        {
            string str[8];
            double d[8];
            double m[4];
            cout << "Enter points\n";
            for (auto& i : str) {
                in >> i;
            }
            for (size_t i = 0; i < 8; ++i) {
                d[i] = stod(str[i]);
            }
            double a = abs(d[0] - d[4]);
            double b = abs(d[1] - d[5]);
            double c = abs(d[2] - d[6]);
            double g = abs(d[3] - d[7]);
            double k = a * c + b * g;
                while(k != 0) {
                    cout<<"you made a mistake\n";
                    for (auto& i : str) {
                        in >> i;
                    }
                    for (size_t i = 0; i < 8; ++i) {
                        d[i] = stod(str[i]);
                    }
                    double a = abs(d[0] - d[4]);
                    double b = abs(d[1] - d[5]);
                    double c = abs(d[2] - d[6]);
                    double g = abs(d[3] - d[7]);
                    k = a * c + b * g;
                }
                    points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
                    points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
                    points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
                    points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
                    vector<double> sides(4);
                    sides[0] = distance(points[0], points[1]);
                    sides[1] = distance(points[1], points[2]);
                    sides[2] = distance(points[2], points[3]);
                    sides[3] = distance(points[3], points[0]);
                    double arg = sides[0];
                    int ans = count_if(sides.begin(), sides.end(), [arg](double& side) {
                        return arg == side;
                        });
                    if (ans != sides.size()) {
                        throw exception();
                    }
                }
                catch (const exception& e) {
                    cerr << e.what() << "\n";
                    auto fg = new Rhomb<T>();
                    return shared_ptr<Rhomb<T>>(fg);
                }
                auto fg = new Rhomb<T>(points[0].first, points[0].second, points[1].first, points[1].second,
                    points[2].first, points[2].second, points[3].first, points[3].second);
                cout << "Figure successfully added!" << "\n";
                return shared_ptr<Figure<T>>(fg);
            
           
    }

    static shared_ptr<Figure<T>> Read(ifstream& fs) {
        vector<pair<T, T>> points(4);
        try
        {
         /*   string str[8];
            double d[8];
            for (auto& i : str) {
                fs >> i;
            }
            for (size_t i = 0; i < 8; ++i) {
                d[i] = stod(str[i]);
            }
        */
            string str[8];
            double d[8];
            double m[4];
            cout << "Enter points\n";
            for (auto& i : str) {
                fs >> i;
            }
            for (size_t i = 0; i < 8; ++i) {
                d[i] = stod(str[i]);
            }
            double a = abs(d[0] - d[2]);
            double b = abs(d[1] - d[3]);
            double c = abs(d[4] - d[6]);
            double g = abs(d[5] - d[7]);
            while ((a * c + b * g) != 0) {
                cout << "you made a mistake\n";
                for (auto& i : str) {
                    fs >> i;
                }
                for (size_t i = 0; i < 8; ++i) {
                    d[i] = stod(str[i]);
                }
                double a = abs(d[0] - d[2]);
                double b = abs(d[1] - d[3]);
                double c = abs(d[4] - d[6]);
                double g = abs(d[5] - d[7]);
            }
            points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
            points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
            points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
            points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
            vector<double> sides(4);
            sides[0] = distance(points[0], points[1]);
            sides[1] = distance(points[1], points[2]);
            sides[2] = distance(points[2], points[3]);
            sides[3] = distance(points[3], points[0]);
            double arg = sides[0];
           // double arg = sides[0];
            int ans = count_if(sides.begin(), sides.end(), [arg](double& side) {
                return arg == side;
                });
            if (ans != sides.size()) {
                throw exception();
            }
        }
        catch (const exception& e) {
            cerr << e.what() << "\n";
            auto fg = new Rhomb<T>();
            return shared_ptr<Rhomb<T>>(fg);
        }
        auto fg = new Rhomb<T>(points[0].first, points[0].second, points[1].first, points[1].second,
            points[2].first, points[2].second, points[3].first, points[3].second);
        cout << "Figure successfully added!" << "\n";
        return shared_ptr<Figure<T>>(fg);
    }
};

template<class T>
class Factory< T, Pentagon<T> > {
public:
    static shared_ptr<Figure<T>> CreateFigure(istream& in) {
        vector<pair<T, T>> points(5);
        try
        {
            string str[10];
            double d[10];
            double m[3];
            cout << "Enter radius and center point\n";
            //for (auto& i : str) {
            //    in >> i;
            //}
            //for (size_t i = 0; i < 10; ++i) {
              //  d[i] =stod(str[i]);
            //}
            for (int i = 0; i < 3; i++) {
                cin >> m[i];
            }
            d[0] = round(m[1] + m[0] * cos(2 * 3.14 / 5));
            d[1] = round(m[2] + m[0] * sin(2 * 3.14 / 5));
            d[2] = round(m[1] + m[0] * cos(4 * 3.14 / 5));
            d[3] = round(m[2] + m[0] * sin(4 * 3.14 / 5));
            d[4] = round(m[1] + m[0] * cos(6 * 3.14 / 5));
            d[5] = round(m[2] + m[0] * sin(6 * 3.14 / 5));
            d[6] = round(m[1] + m[0] * cos(8 * 3.14 / 5));
            d[7] = round(m[2] + m[0] * sin(8 * 3.14 / 5));
            d[8] = round(m[1] + m[0] * cos(10 * 3.14 / 5));
            d[9] = round(m[2] + m[0] * sin(10 * 3.14 / 5));
            points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
            points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
            points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
            points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
            points[4] = { static_cast<T>(d[8]), static_cast<T>(d[9]) };
            vector<double> sides(5);
            sides[0] = distance(points[0], points[1]);
            sides[1] = distance(points[1], points[2]);
            sides[2] = distance(points[2], points[3]);
            sides[3] = distance(points[3], points[4]);
            sides[4] = distance(points[0], points[4]);
            double arg = sides[0];
        }
        catch (const exception& e) {
            cerr << e.what() << "\n";
            auto fg = new Pentagon<T>();
            return shared_ptr<Pentagon<T>>(fg);
        }
        auto fg = new Pentagon<T>(points[0].first, points[0].second, points[1].first, points[1].second,
            points[2].first, points[2].second, points[3].first, points[3].second,
            points[4].first, points[4].second);
        cout << "Figure successfully added!" << "\n";
        return shared_ptr<Figure<T>>(fg);
    }

    static shared_ptr<Figure<T>> Read(ifstream& fs) {
        vector<pair<T, T>> points(5);
        try
        {
            /*string str[10];
            double d[10];
            for (auto& i : str) {
                fs >> i;
            }
            for (size_t i = 0; i < 10; ++i) {
                d[i] = stod(str[i]);
            }
            */
            string str[10];
            double d[10];
            double m[3];
            cout << "Enter radius and center point\n";
            //for (auto& i : str) {
            //    in >> i;
            //}
            //for (size_t i = 0; i < 10; ++i) {
              //  d[i] =stod(str[i]);
            //}
            for (int i = 0; i < 3; i++) {
                cin >> m[i];
            }
            d[0] = round(m[1] + m[0] * cos(2 * 3.14 / 5));
            d[1] = round(m[2] + m[0] * sin(2 * 3.14 / 5));
            d[2] = round(m[1] + m[0] * cos(4 * 3.14 / 5));
            d[3] = round(m[2] + m[0] * sin(4 * 3.14 / 5));
            d[4] = round(m[1] + m[0] * cos(6 * 3.14 / 5));
            d[5] = round(m[2] + m[0] * sin(6 * 3.14 / 5));
            d[6] = round(m[1] + m[0] * cos(8 * 3.14 / 5));
            d[7] = round(m[2] + m[0] * sin(8 * 3.14 / 5));
            d[8] = round(m[1] + m[0] * cos(10 * 3.14 / 5));
            d[9] = round(m[2] + m[0] * sin(10 * 3.14 / 5));
            points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
            points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
            points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
            points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
            points[4] = { static_cast<T>(d[8]), static_cast<T>(d[9]) };
            vector<double> sides(5);
            sides[0] = distance(points[0], points[1]);
            sides[1] = distance(points[1], points[2]);
            sides[2] = distance(points[2], points[3]);
            sides[3] = distance(points[3], points[4]);
            sides[4] = distance(points[0], points[4]);
            double arg = sides[0];
            int ans = count_if(sides.begin(), sides.end(), [arg](double& side) {
                return arg == side;
                });
            if (ans != sides.size()) {
                throw exception();
            }
        }
        catch (const exception& e) {
            auto fg = new Pentagon<T>();
            return shared_ptr<Pentagon<T>>(fg);
        }
        auto fg = new Pentagon<T>(points[0].first, points[0].second, points[1].first, points[1].second,
            points[2].first, points[2].second, points[3].first, points[3].second,
            points[4].first, points[4].second);
        cout << "Figure successfully added!" << "\n";
        return shared_ptr<Figure<T>>(fg);
    }
};

template<class T>
class Factory< T, Trapeze<T> > {
public:
    static shared_ptr<Figure<T>> CreateFigure(istream& is) {
        vector <pair<T, T>> points(4);
        try
        {
            string str[8];
            double d[8];
            cout << "Enter 8 values: p1(x,y), p2(x,y), p3(x,y), p4(x,y), where p1,p4 - first base, p2,p3 - second base\n";
            for (auto& i : str) {
                is >> i;
            }
            for (size_t i = 0; i < 8; ++i) {
                d[i] = stod(str[i]);
            }
            points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
            points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
            points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
            points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
            auto diff_y_0 = static_cast<double>(points[2].second - points[1].second);
            auto diff_y_1 = static_cast<double>(points[3].second - points[0].second);
            auto diff_x_0 = static_cast<double>(points[2].first - points[1].first);
            auto diff_x_1 = static_cast<double>(points[3].first - points[0].first);
            if (diff_y_0 / diff_x_0 != diff_y_1 / diff_x_1) {
                throw exception();
            }
        }
        catch (const exception& e) {
            cerr << e.what() << "\n";
            auto fg = new Trapeze<T>();
            return shared_ptr<Figure<T>>(fg);
        }
        auto fg = new Trapeze<T>(points[0].first, points[0].second, points[1].first, points[1].second,
            points[2].first, points[2].second, points[3].first, points[3].second);
        cout << "Figure successfully added!" << "\n";
        return shared_ptr<Figure<T>>(fg);
    }

    static shared_ptr<Figure<T>> Read(ifstream& fs) {
        vector<pair<T, T>> points(4);
        try
        {
            string str[8];
            double d[8];
            for (auto& i : str) {
                fs >> i;
            }
            for (size_t i = 0; i < 8; ++i) {
                d[i] = stod(str[i]);
            }
            points[0] = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
            points[1] = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
            points[2] = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
            points[3] = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
            auto diff_y_0 = static_cast<double>(points[2].second - points[1].second);
            auto diff_y_1 = static_cast<double>(points[3].second - points[0].second);
            auto diff_x_0 = static_cast<double>(points[2].first - points[1].first);
            auto diff_x_1 = static_cast<double>(points[3].first - points[0].first);
            if (diff_y_0 / diff_x_0 != diff_y_1 / diff_x_1) {
                throw exception();
            }
        }
        catch (const exception& e) {
            cerr << e.what() << "\n";
            auto fg = new Trapeze<T>();
            return shared_ptr<Figure<T>>(fg);
        }
        auto fg = new Trapeze<T>(points[0].first, points[0].second, points[1].first, points[1].second,
            points[2].first, points[2].second, points[3].first, points[3].second);
        cout << "Figure successfully added!" << "\n";
        return shared_ptr<Figure<T>>(fg);
    }
};