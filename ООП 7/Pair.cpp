#include <iostream>
#include "Pair.h"
using namespace std;

Pair::Pair() {
	a = 0;
	b = 0.0;
}
Pair::Pair(int n1, double n2) {
	a = n1;
	b = n2;
}
Pair::Pair(const Pair& N) {
	a = N.a;
	b = N.b;
}
Pair::~Pair() {}
//Перегрузка операции присваивания
Pair& Pair::operator=(const Pair& N) {
	if (&N == this)
		return *this;
	a = N.a;
	b = N.b;
	return *this;
}
//Метод для умножения элементов списков a[i]*b[i]
Pair operator*(Pair& P1, Pair& P2) {
	Pair result;
	result.a = P1.a * P2.a;
	result.b = P1.b * P2.b;
	return result;
}
//Перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Pair& N) {
	cout << "Целое число? "; in >> N.a;
	cout << "Дробное число? "; in >> N.b;
	return in;
}
//Перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Pair& N) {
	return (out << "(" << N.a << " : " << N.b << ")");
}
