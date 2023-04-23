#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

//Конструктор без параметров
Person::Person() {
	name = "Пусто";
	age = 0;
}
//Конструктор с параметрами
Person::Person(string n, int a) {
	name = n;
	age = a;
}
//Конструктор копирования
Person::Person(const Person& P) {
	name = P.name;
	age = P.age;
}
//Деструктор
Person::~Person(){}
//Геттер и сеттер для поля name
string Person::get_name() {
	return name;
}
void Person::set_name(string n) {
	name = n;
}
//Геттер и сеттер для поля age
int Person::get_age() {
	return age;
}
void Person::set_age(int a) {
	age = a;
}
//Перегрузка операции присваивания
Person& Person::operator=(const Person& P) {
	if (&P == this)
		return *this;
	name = P.name;
	age = P.age;
	return *this;
}
//Перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Person& P) {
	cout << "Имя? "; in >> P.name;
	cout << "Возраст? "; in >> P.age;
	return in;
}
//Перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Person& P) {
	return (out << "Имя: " << P.name << endl << "Возраст: " << P.age << endl);
}