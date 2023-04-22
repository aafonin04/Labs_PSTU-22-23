#include <iostream>
#include <string>
#include "Salary.h"
using namespace std;

Salary::Salary() { //Конструктор без параметров
	name = "Test";
	pay = 100;
	bonus = 100 * 0.5;
}

Salary::Salary(string n, double p, int b) { //Конструктор с параметрами
	name = n;
	pay = p;
	bonus = b;
}

Salary::Salary(const Salary &t) { //Конструктор копирования
	name = t.name;
	pay = t.pay;
	bonus = t.bonus;
}

Salary::~Salary(){} //Деструктор
//Селектор и модификатор поля name
string Salary::get_name() {
	return name;
}
void Salary::set_name(string n) {
	name = n;
}
//Селектор и модификатор поля pay
double Salary::get_pay() {
	return pay;
}
void Salary::set_pay(double p) {
	pay = p;
}
//Селектор и модификатор поля bonus
int Salary::get_bonus() {
	return bonus;
}
void Salary::set_bonus(int b) {
	bonus = b;
}
//Метод для просмотра полей
void Salary::show() {
	cout << "ФИО: " << name << endl;
	cout << "Оклад: " << pay << endl;
	cout << "Премия: " << bonus << endl;
}