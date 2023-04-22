#include <iostream>
using namespace std;
#pragma once

class Pair {
private:
	int a;
	double b;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	int get_a();
	void set_a(int);
	double get_b();
	void set_b(double);
	//Перегруженные операции
	Pair& operator=(const Pair&); //Присваивание
	Pair operator-(const Pair&); //Вычитание
	Pair operator+(int); //Сложения (целые числа)
	Pair operator+(double); //Сложение (дробные числа)
	//Перегрузка операторов ввода/вывода
	friend istream& operator>>(istream& in, Pair& N);
	friend ostream& operator<<(ostream& out, const Pair& N);
};

