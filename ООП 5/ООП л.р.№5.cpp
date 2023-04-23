#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Vector v(5); //Вектор из 5 элементов
	cout << "Экземпляр класса Person:" << endl;
	Person a; //Объект класса Person
	cin >> a;
	cout << endl << "Экземпляр класса Student:" << endl;
	Student b; //Объект класса Student
	cin >> b;
	cout << endl;
	cout << "Вектор из экземпляров: " << endl;
	Object* p = &a; ; //Ставим указатель на объект класса Person
	v.Add(p); //Добавляем объект в вектор
	p = &b; //Ставим указатель на объект класса Student
	v.Add(p); //Добавляем объект в вектор
	cout << v; //Вывод вектора
	return 0;
}