#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Person :
    public Object
{
protected:
	string name;
	int age;
public:
	//Конструктооры и деструктор
	Person();
	Person(string, int);
	Person(const Person&);
	virtual ~Person();
	//Геттер и сеттер для поля name
	string get_name();
	void set_name(string);
	//Геттер и сеттер для поля age
	int get_age();
	void set_age(int);
	//Метод для просмотра атрибутов с помощью указателя
	void Show();
	//Перегрузка оператора присваивания
	Person& operator=(const Person&);
	//Глобальные операторы функции для ввода/вывода
	friend istream& operator>>(istream& in, Person&);
	friend ostream& operator<<(ostream& out, const Person&);
};

