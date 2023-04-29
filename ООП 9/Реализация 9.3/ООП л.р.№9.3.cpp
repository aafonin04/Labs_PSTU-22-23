#include <iostream>
#include <Windows.h>
#include "List.h"
#include "Error.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		int n1, n2, n3, i, s;
		cout << "Введите размер первого списка: ";
		cin >> n1;
		List l1(n1);
		cout << "Ваш список: " << l1;
		cout << "Введите индекс элемента, который вы хотите получить: "; cin >> i;
		cout << "Элемент: " << l1[i] << endl << endl;
		cout << "Введите размер второго списка: ";
		cin >> n2;
		List l2(n2);
		cout << "Ваш список: " << l2;
		cout << "Умножение списков: " << l1 * l2 << endl;
		cout << "Введите размер третьего списка: ";
		cin >> n3;
		List l3(n3);
		cout << "Ваш список: " << l3;
		cout << "На сколько элементов вы хотите сместиться? "; cin >> s;
		l3.shift(s);
		cout << "Ваш список: " << l3;
		cout << "Удаление списка" << endl;
		for (int j = 0; j < n3 + 1; j++) {
			cout << l3;
			l3.pop();
		}
	}
	catch (Error& e) {
		e.what();
	}
	return 0;
}