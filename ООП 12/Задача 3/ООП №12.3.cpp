#include <iostream>
#include <set>
#include "List.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int n; double one, two;
	cout << "Введите размер: "; cin >> n;
	List<float> m(n);
	m.Print();
	cout << "\nДобавление среднего арифметического\n"; m.List_mean();  m.Print();
	cout << "\nУдаление элементов из диапазона\n";
	m.Delete_range(); m.Print();
	cout << "\nДобавление суммы максимального и минимального из элементов\n"; m.Max_min(); m.Print();
	return 0;
}