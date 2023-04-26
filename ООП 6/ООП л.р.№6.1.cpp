#include <iostream>
#include "List.h"
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List l1(5);
	cout << "Первый список l1: " << l1;
	cout << "Длина списка: " << l1() << endl;
	cout << "Первый элемент спика: " << l1[0] << endl;
	cout << "Последний элемент списка: " << l1[l1() - 1] << endl;

	List l2;
	cout << endl << "Второй список l2: " << endl;
	cin >> l2;
	cout << "Ваш список: " << l2 << endl;
	
	List l3;
	l3 = l1 * l2;
	cout << "Третий список l3=l1*l2: " << l3 << endl;

	List l4(7);
	cout << "Четвертый список: " << l4;
	int n;
	Iterator i = l4.f();
	cout << "Введите индекс элемента списка, к которому хотите перейти: "; cin >> n;
	i=i + n;
	cout << "Элемент под индексом " << n << ": " << *i << endl;

	return 0;
}

