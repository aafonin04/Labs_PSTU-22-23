#pragma once
#include "Object.h"
#include "Event.h"

class Vector
{
protected:
	Object** beg; //Указатель на первый элемент вектора
	int size; //Размер
	int cur; //Текущая позиция
public:
	Vector();
	Vector(int);
	~Vector();
	void Add(); //Добавление элемента в вектор
	void Del(); //Удаление элемента из вектора
	void Show();
	void HandleEvent(const TEvent& e);
	int operator()();//размер вектора
};

