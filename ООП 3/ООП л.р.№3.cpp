﻿#include <iostream>
#include "Pair.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	Pair Obj1; //Конструктор без параметров
	cout << "Введите значения первого экземпляра класса" << endl;
	cin >> Obj1; //Ввод экземпляра
	cout << "Первый экземпляр класса: ";
	cout << Obj1 << endl << endl; //Вывод экземпляра

	int i; //Целое число
	double d; //Дробное число
	int n;
	cout << "Какое число вы хотите добавить к экземпляру класса?" << endl;
	cout << "1.Целое число" << endl;
	cout << "2.Дробное число" << endl;
	cout << "Ваш выбор: "; cin >> n;

	switch (n) {
	case 1: {
		cout << "Введите целое число: "; cin >> i;
		Obj1 = Obj1 + i; //Добавление к экземпляру целого числа
		cout << "Измененный экземпляр класса: ";
		cout << Obj1 << endl;
		break;
	}
	case 2: {
		cout << "Введите дробное число: "; cin >> d;
		Obj1 = Obj1 + d; //Добавление к экземпляру дробного числа
		cout << "Измененный экземпляр класса: ";
		cout << Obj1 << endl;
		break;
	}
	default: cout << "Неизвестная операция" << endl;
	}

	cout << endl;
	Pair Obj2; //Конструктор без параметров 
	cout << "Введите значения второго экземпляра класса" << endl;
	cin >> Obj2; //Ввод экземпляра
	cout << "Второй экземпляр класса: ";
	cout << Obj2 << endl << endl; //Вывод экземпляра
	Obj1 = Obj1 - Obj2; //Вычитание экземпляров
	cout << "Вычитание второго экземпляра класса из первого: " << Obj1 << endl;

	return 0;
}