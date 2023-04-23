#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string name;
	int age;
public:
	//Конструктооры и деструктор
	Person();
	Person(string, int);
	Person(const Person&);
	~Person();
	//Геттер и сеттер для поля name
	string get_name();
	void set_name(string);
	//Геттер и сеттер для поля age
	int get_age();
	void set_age(int);
	//Перегрузка оператора присваивания
	Person& operator=(const Person&);
	//Глобальные операторы функции для ввода/вывода
	friend istream& operator>>(istream& in, Person&);
	friend ostream& operator<<(ostream& out, const Person&);
};

