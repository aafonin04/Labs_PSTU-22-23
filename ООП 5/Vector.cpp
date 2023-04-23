#include "Vector.h"

//Конструктор без параметров
Vector::Vector(void)
{
	beg = 0;
	size = 0;
	cur = 0;
}
//Конструктор с параметрами
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//Деструктор
Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
//Добавление объекта, на который указывает указатель p в векторе
void Vector::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}
//Операция вывода
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Пусто" << endl;
	Object** p = v.beg; //Указатель на указатель типа Object
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show(); //Вызов метода Show() 
		cout << "----------" << endl;
		p++; //Передвигаем указатель на следующий объект
	}
	return out;
}
