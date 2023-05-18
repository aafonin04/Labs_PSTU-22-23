#include <iostream>
using namespace std;
#pragma once

class Pair {
private:
	int a;
	double b;
public:
	void random() {
		a = rand() % 10;
		b = (rand() % 101 - 50) / 10.0;
	}
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
	Pair operator+(const Pair&);
	Pair operator /(int);
	bool operator>=(const Pair&);
	bool operator<=(const Pair&);
	bool operator>(const Pair&);
	bool operator<(const Pair&);
	//Перегрузка операторов ввода/вывода
	friend istream& operator>>(istream& in, Pair& N);
	friend ostream& operator<<(ostream& out, const Pair& N);
};