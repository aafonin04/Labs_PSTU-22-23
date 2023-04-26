#include "List.h"
#include "List.cpp"
#include "Pair.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Инициализация и вывод элементов списка
	List<double>l1(5,5.7);
	cout << "Список l1: " << l1 << endl;
	//Ввод и вывод значений списка
	cout << "Список l2: " << endl;
	List<double>l2;
	cin >> l2;
	cout << "Ваш список: " << l2 << endl;
	//Операция присваивания
	List<double>l3;
	cout << "Копирование из l2 в l3: " << endl;
	l3 = l2;
	cout << "Ваш список: " << l3;
	int n;
	cout << "Элемент под каким номером вы хотите получить? "; cin >> n;
	cout << "Элемент под номером " << n << ": " << '[' << l3[n - 1] << ']' << endl; //Доступ по индексу
	cout << "Длина списка: " << l3() << endl << endl; //Получение длины списка
	
	List<double>l4;
	l4 = l3 * l1; //Операция умножения элементов списков a[i]*b[i]
	cout << "Умножение элементов двух списков l4=l3*l1: " << l4 << endl;

	cout << "Введите экзепляр p1:" << endl;
	Pair p1;
	cin >> p1;
	cout << "Ваш экземпляр: " << p1 << endl << endl;

	cout << "Введите экзепляр p2:" << endl;
	Pair p2;
	cin >> p2;
	cout << "Ваш экземпляр: " << p2 << endl << endl;

	Pair p3;
	p3 = p2 * p1;
	cout << "Экземпляр p3=p2*p1: " << p3 << endl << endl;

	cout << "Список l5, состоящий из экземпляра p3: " << endl;
	List<Pair>l5(5,p3);
	cout << l5 << endl;

	cout << "Список l6, состоящий из элемнтов типа Pair:" << endl;
	List<Pair>l6;
	cin >> l6;
	cout << l6 << endl;

	cout << "Копирование из l6 в l7: " << endl;
	List<Pair>l7;
	l7 = l6;
	cout << "Ваш список: " << l7;
	int i;
	cout << "Элемент под каким номером вы хотите получить? "; cin >> i;
	cout << "Элемент под номером " << i << ": " << '[' << l7[i - 1] << ']' << endl;
	cout << "Длина списка: " << l7() << endl;

	List<Pair>l8;
	l8 = l7 * l5;
	cout << "Умножение элементов двух списков l8=l7*l5: " << l8 << endl;
	return 0;
}