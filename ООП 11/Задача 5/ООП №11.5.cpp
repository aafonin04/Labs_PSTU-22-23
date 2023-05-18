#include "List.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int n; 
	double one, two;
	cout << "Размер списка: "; cin >> n;
	List<int> l(n);
	l.print();
	cout << "\nСписок после добавления среднего арифметического\n"; l.mean();  l.print();
	cout << "\n\nДобавление суммы максимального и минимального"; l.minmax(); l.print();
	cout << "\n\nУдаление из диапазона\n";
	cout << "\nЛевая граница: "; cin >> one;
	cout << "\nПравая граница: "; cin >> two;
	l.range(one, two); l.print();
	cout << endl;
	return 0;
}