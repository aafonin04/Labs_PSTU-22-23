#pragma once
#include <iostream>
using namespace std;

class Pair {
private:
	int a;
	double b;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	//Перегруженные операции
	Pair& operator=(const Pair&); //Присваивание
	friend Pair operator*(Pair&, Pair&);
	//Перегрузка операторов ввода/вывода
	friend istream& operator>>(istream& in, Pair& N);
	friend ostream& operator<<(ostream& out, const Pair& N);
};

