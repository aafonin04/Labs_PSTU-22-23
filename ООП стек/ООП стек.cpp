#include <iostream>
#include <string>
#include <Windows.h>
#include "Stack.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Stack s1;
	cin >> s1;
	cout << "Ваш стек: " << s1 << endl;
	string key;
	cout << "Введите ключ элемента, который вы хотите удалить: ";  cin >> key;
	s1.deletekey(key);
	cout << "Измененный стек: " << s1 << endl;
	int n;
	cout << "Введите номер элемента, перед которым нужно вставить новые элементы стека: ";  cin >> n;
	s1.newelem(n);
	cout << "Измененный стек: " << s1 << endl;
	return 0;
}