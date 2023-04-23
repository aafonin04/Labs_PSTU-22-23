#include <iostream>
#include <string>
#include "Student.h"
#include "Person.h"
using namespace std;

//����������� ��� ����������
Student::Student() :Person() {
	subject = "�����";
	mark = 0;
}
//����������� � �����������
Student::Student(string n, int a, string s, int m) :Person(n, a) {
	subject = s;
	mark = m;
}
//����������� �����������
Student::Student(const Student& S) {
	name = S.name;
	age = S.age;
	subject = S.subject;
	mark = S.mark;
}
//����������
Student::~Student() {}
//������ � ������ ��� ���� subject
string Student::get_subject() {
	return subject;
}
void Student::set_subject(string s) {
	subject = s;
}
//������ � ������ ��� ���� mark
int Student::get_mark() {
	return mark;
}
void Student::set_mark(int m) {
	mark = m;
}
//����� ��� �������� ������
void Student::ChekMark() {
	if (mark < 3)
		cout << "� �������� ���� �������������������� ������" << endl;
	else
		cout << "� �������� ��� �������������������� ������" << endl;
}
//����� ��� ��������� ��������� � ������� ���������
void Student::Show() {
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "�������: " << subject << endl;
	cout << "������: " << mark << endl;
}
//���������� �������� ������������
Student& Student::operator=(const Student& S) {
	if (&S == this)
		return *this;
	name = S.name;
	age = S.age;
	subject = S.subject;
	mark = S.mark;
	return *this;
}
//���������� ���������� �������-�������� �����
istream& operator>>(istream& in, Student& S) {
	cout << "���? "; in >> S.name;
	cout << "�������? "; in >> S.age;
	cout << "�������? "; in >> S.subject;
	cout << "������? "; in >> S.mark;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Student& S) {
	return (out << "���: " << S.name << endl << "�������: " << S.age << endl
		<< "�������: " << S.subject << endl << "������: " << S.mark << endl);
}
