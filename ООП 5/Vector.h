#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Vector
{
private:
	Object** beg; //Указатель на превый элемент вектора
	int size; //Размер вектора
	int cur; //Текущая поизиция 
public:
	//Контструкторы и деструктор
	Vector();
	Vector(int);
	~Vector();
	//Добавление эелемнета в вектор
	void Add(Object*);
	//Операция вывода
	friend ostream& operator<<(ostream& out, const Vector&);
};

