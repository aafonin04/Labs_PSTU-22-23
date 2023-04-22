#include <iostream>
#include <string>
#include "Salary.h"
using namespace std;

Salary::Salary() { //����������� ��� ����������
	name = "Test";
	pay = 100;
	bonus = 100 * 0.5;
}

Salary::Salary(string n, double p, int b) { //����������� � �����������
	name = n;
	pay = p;
	bonus = b;
}

Salary::Salary(const Salary &t) { //����������� �����������
	name = t.name;
	pay = t.pay;
	bonus = t.bonus;
}

Salary::~Salary(){} //����������
//�������� � ����������� ���� name
string Salary::get_name() {
	return name;
}
void Salary::set_name(string n) {
	name = n;
}
//�������� � ����������� ���� pay
double Salary::get_pay() {
	return pay;
}
void Salary::set_pay(double p) {
	pay = p;
}
//�������� � ����������� ���� bonus
int Salary::get_bonus() {
	return bonus;
}
void Salary::set_bonus(int b) {
	bonus = b;
}
//����� ��� ��������� �����
void Salary::show() {
	cout << "���: " << name << endl;
	cout << "�����: " << pay << endl;
	cout << "������: " << bonus << endl;
}