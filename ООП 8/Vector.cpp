#include "Vector.h"
#include "MAGAZIN.h"
#include "Event.h"
#include <iostream>
using namespace std;

Vector::Vector() {
	beg = nullptr;
	cur = 0;
	size = 0;
}
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
	beg = 0;
}
//Добавление объекта, на который указывает указатель p в вектор
void Vector::Add()
{
	Object* p;
	//Выбор из объектов двух возможных классов
	cout << "1.Печатное издание" << endl;
	cout << "2.Журнал" << endl;
	int y;
	cin >> y;
	if (y == 1) { //Добавление объекта класса PRINT
		PRINT* a = new PRINT;
		a->Input(); //Ввод значений атрибутов
		p = a;
		if (cur < size) {
			beg[cur] = p; //Добавление в вектор
			cur++;
		}
	}
	else {
		if (y == 2) { //добавление объекта класса MAGAZIN
			MAGAZIN* b = new MAGAZIN;
			b->Input();
			p = b;
			if (cur < size) {
				beg[cur] = p;
				cur++;
			}
		}
		else
			return;
	}
}
//Удаление элемента из вектора
void Vector::Del()
{
	if (cur == 0)
		return;
	cur--;
}
void Vector::Show()
{
	if (cur == 0)
		cout << "Вектор пустой" << endl;
	Object** p = beg; //Указатель на указатель типа Object
	for (int i = 0; i < cur; i++) {
		(*p)->Show(); //Вызов метода Show()
		p++; //Передвигаем указатель на следующий объект
	}
}
void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e); //Вызов метода 
			p++; //Передвигаем указатель на следующий объект
		}
	}
}
//Операция, которая возвращает размер вектора
int Vector::operator ()()
{
	return size;
}
