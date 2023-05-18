#include <iostream>
#include "List.h"
#include "Pair.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	cout << "Введите элементы списка:" << endl;
	List<Pair>l(n);
	cout << "Ваш список: "; l.Print();
	l.List_mean();
	cout << "Список после добавления среднего арифметического: "; l.Print();
	l.Delete_range();
	cout << "Список после удаления элементов: "; l.Print();
	l.Max_min();
	cout << "Список после добавления суммы максимального и минимального из элементов: "; l.Print();
	return 0;
}