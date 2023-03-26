// Капалин Д.С. М80-201Б-20 Вариант 3
// Создать класс Rational для для работы с рациональными дробями.
// обязательно должны быть реализованы следующие операции:
// сложения, вычитания, умножения, деления, сокращения. 
//

#include "OOP2.h"
using namespace std;
class Rational {
private:
	int ch;
	int zn;
public:
	Rational() {
		ch = 0;
		zn = 1;
	}
	Rational(int a, int b) {
		ch = a;
	    zn = b;
	}
	void getRational()
	{
		cout << ch << "/" << zn << "\n";
	}
	void putRational() {
		printf("Введите числитель\n");
		scanf("%d", &ch);
		printf("Введите знаменатель\n");
		scanf("%d", &zn);
		if (zn == 0) {
			while (zn == 0) {
				printf("Введите знаменатель != 0\n");
				scanf("%d", &zn);
			}
	    }
	}
	Rational operator+(Rational d) {
		Rational d1;
		if (zn != d.zn) {
			d1.ch = ch * d.zn + d.ch * zn;
			d1.zn = d.zn * zn;
		}
		else {
			d1.ch = ch + d.ch;
			d1.zn = zn;
		}
		return d1;
	}
	Rational operator-() {
		Rational d1;

		d1.ch = -ch;
		d1.zn = zn;
		if (d1.zn < 0 && d1.ch < 0) {
			d1.zn *= -1;
			d1.ch *= -1;
		}
		return d1;
	}
	Rational operator-(Rational d1) {
		Rational d2;
		if (zn != d1.zn) {
			d2.ch = ch * d1.zn - zn * d1.ch;
			d2.zn = d1.zn * zn;
		}
		else {
			d2.ch = ch + d1.ch;
			d2.zn = zn;
		}
		return d2;
	}
	Rational operator*(Rational d1) {
		Rational d2;
		d2.ch = ch * d1.ch;
		d2.zn = zn * d1.zn;
		if (d2.zn < 0 && d2.ch < 0) {
			d2.zn *= -1;
			d2.ch *= -1;
		}
		return d2;
	}
	Rational operator/(Rational d1) {
		Rational d2;
		d2.ch = ch * d1.zn;
		d2.zn = zn * d1.ch;
		if (d2.zn < 0 && d2.ch < 0) {
			d2.zn *= -1;
			d2.ch *= -1;
		}
		return d2;
	}
	void reduce() {
		int a = abs(ch);
		int b = abs(zn);
		if (a == b)
		{
			ch = ch / zn;
			zn = 1;
		}
		else{
			while (a != b) {
				if (a > b) {a = a - b;}
				else if (a < b) {b = b - a;}
			}
			ch = ch / a;
			zn = zn / a;
		}
	}
	bool operator> (  Rational d1) {
		Rational d2(ch,zn);
		if (zn < d1.zn) { return true; }
		else if (zn > d1.zn) { return false; }
		else if (zn == d1.zn) {
			if (ch > d1.ch) { return true; }
			else if (ch < d1.ch) { return false; }
		}
	}
	bool operator< ( Rational d1) {
		Rational d2(ch, zn);
		if (zn < d1.zn) { return false; }
		else if (zn > d1.zn) { return true; }
		else if (zn == d1.zn) {
			if (ch > d1.ch) { return false; }
			else if (ch < d1.ch ) { return true; }
		}
	}
	
	friend ostream& operator<<(ostream& out, const Rational& d);
	friend istream& operator>>(istream& in, Rational& d);
	friend bool operator==(Rational d, Rational d1);
};
bool operator==(Rational d, Rational d1) {
	if (d.ch == d1.ch && d.zn == d1.zn) { return true; }
	else { return false; }
}
ostream& operator<<(ostream& out, const Rational &d) {
	out << d.ch << "/" << d.zn;
	return out;
}
istream& operator>>(istream& in, Rational& d) {
	in >> d.ch;
	in >> d.zn;
	return in;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Rational d;
	int c = 0;
	while (1) {
		cout << "1.Ввести дробь " << "2.Сложить дроби " << "3.Вычесть дроби " << "4.Сократить дробь " << "5.Умножить дроби " << "6.Поделить дроби " <<"7.Сравнение"  << "8.Выход" << "\n";
		cin >> c;
		if (c == 1) {
			cout << "Введите дробь" << "\n";
			d.putRational();
			cout << "Вы ввели: " << d << "\n";
		}
		if (c == 2) {
			cout << "Первое слагаемое: " << d << "\n";
			cout << "Введите второе слагаемое" << "\n";
			Rational d1;
			cin >> d1;
			Rational sum;
			sum = d1 + d;
			cout << "Результат: " << sum << "\n";
		}
		if (c == 3) {
			cout << "Уменьшаемое: " << d << "\n";
			cout << "Введите вычитаемое:"<< "\n";
			Rational d1, razn;
			cin >> d1;
			razn = d - d1;
			cout << "Результат: " << razn << "\n";
		}
		if (c == 4) {
			d.reduce();
			cout << "Сокращенная дробь: " << d << "\n";
		}
		if (c == 5) {
			cout << "Первое множитель: " << d << "\n";
			cout << "Введите второй множитель" << "\n";
			Rational d1, rez;
			cin >> d1;
			cout <<"Результат:"<< d1 * d << "\n";

		}
		if (c == 6) {
			cout << "Делимое: " << d << "\n";
			cout << "Введите делитель" << "\n";
			Rational d1;
			cin >> d1;
			cout <<"Результат:"<< d / d1 << "\n";
		}
		if (c == 7) {
			cout << "Первая дробь: " << d << "\n";
			cout << "Введите вторую дробь: " << "\n";
			Rational d1;
			cin >> d1;
			if (d < d1) { cout << "Меньшее значение:  " << d << " " << "Большее значение:  "<< d1 <<  "\n"; }
			if (d > d1){ cout << "Меньшее значение:  " << d1 <<" " << "Большее значение:  " << d << "\n"; }
			if (d == d1) { cout << "Значения равны" << "\n"; }
		}
		if (c == 8) { exit(1); }
	}
	return 0;
}
