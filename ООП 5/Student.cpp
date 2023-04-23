#include <iostream>
#include <string>
#include "Student.h"
#include "Person.h"
using namespace std;

//Конструктор без параметров
Student::Student() :Person() {
	subject = "Пусто";
	mark = 0;
}
//Конструктор с параметрами
Student::Student(string n, int a, string s, int m) :Person(n, a) {
	subject = s;
	mark = m;
}
//Конструктор копирования
Student::Student(const Student& S) {
	name = S.name;
	age = S.age;
	subject = S.subject;
	mark = S.mark;
}
//Деструктор
Student::~Student() {}
//Геттер и сеттер для поля subject
string Student::get_subject() {
	return subject;
}
void Student::set_subject(string s) {
	subject = s;
}
//Геттер и сеттер для поля mark
int Student::get_mark() {
	return mark;
}
void Student::set_mark(int m) {
	mark = m;
}
//Метод для проверки оценок
void Student::ChekMark() {
	if (mark < 3)
		cout << "У студента есть неудовлетворительные оценки" << endl;
	else
		cout << "У студента нет неудовлетворительных оценок" << endl;
}
//Метод для просмотра атрибутов с помощью указателя
void Student::Show() {
	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
	cout << "Предмет: " << subject << endl;
	cout << "Оценка: " << mark << endl;
}
//Перегрузка операции присваивания
Student& Student::operator=(const Student& S) {
	if (&S == this)
		return *this;
	name = S.name;
	age = S.age;
	subject = S.subject;
	mark = S.mark;
	return *this;
}
//Перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Student& S) {
	cout << "Имя? "; in >> S.name;
	cout << "Возраст? "; in >> S.age;
	cout << "Предмет? "; in >> S.subject;
	cout << "Оценка? "; in >> S.mark;
	return in;
}
//Перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Student& S) {
	return (out << "Имя: " << S.name << endl << "Возраст: " << S.age << endl
		<< "Предмет: " << S.subject << endl << "Оценка: " << S.mark << endl);
}
