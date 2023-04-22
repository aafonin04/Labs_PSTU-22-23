#pragma once
#include <iostream>
#include <string>
using namespace std;

class Salary
{
private:
	string name; //ФИО
	double pay; //Оклад
	int bonus; //Премия (% от оклада)
public:
	Salary(); //Конструктор без параметров
	Salary(string, double, int); //Конструктор с параметрами
	Salary(const Salary&); //Конструткор копирования
	~Salary(); //Деструктор
	string get_name(); //Селектор поля name
	void set_name(string); //Модификтор поля name
	double get_pay(); //Селектор поля pay
	void set_pay(double); //Модификатор поля pay
	int get_bonus(); //Селектор поля bonus
	void set_bonus(int); //Модификатор поля bonus
	void show(); //Просмотр полей
};

