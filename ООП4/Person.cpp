#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

//����������� ��� ����������
Person::Person() {
	name = "�����";
	age = 0;
}
//����������� � �����������
Person::Person(string n, int a) {
	name = n;
	age = a;
}
//����������� �����������
Person::Person(const Person& P) {
	name = P.name;
	age = P.age;
}
//����������
Person::~Person(){}
//������ � ������ ��� ���� name
string Person::get_name() {
	return name;
}
void Person::set_name(string n) {
	name = n;
}
//������ � ������ ��� ���� age
int Person::get_age() {
	return age;
}
void Person::set_age(int a) {
	age = a;
}
//���������� �������� ������������
Person& Person::operator=(const Person& P) {
	if (&P == this)
		return *this;
	name = P.name;
	age = P.age;
	return *this;
}
//���������� ���������� �������-�������� �����
istream& operator>>(istream& in, Person& P) {
	cout << "���? "; in >> P.name;
	cout << "�������? "; in >> P.age;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Person& P) {
	return (out << "���: " << P.name << endl << "�������: " << P.age << endl);
}