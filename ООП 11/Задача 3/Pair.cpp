#include <iostream>
#include <ctime>
#include "Pair.h"
using namespace std;


Pair::Pair() {
	a = 0;
	b = 0.0;
}

Pair::Pair(int n1, double n2) {
	a = n1;
	b = n2;
}

Pair::Pair(const Pair& N) {
	a = N.a;
	b = N.b;
}

Pair::~Pair() {}

int Pair::get_a() {
	return a;
}
void Pair::set_a(int n) {
	a = n;
}

double Pair::get_b() {
	return b;
}
void Pair::set_b(double n) {
	b = n;
}

//���������� �������� ������������
Pair& Pair::operator=(const Pair& N) {
	if (&N == this)
		return *this;
	a = N.a;
	b = N.b;
	return *this;
}
//���������� �������� �������� ���������
Pair Pair::operator-(const Pair& N) {
	Pair temp;
	temp.a = a - N.a;
	temp.b = b - N.b;
	return temp;
}
//���������� �������� �������� �������� ��� ���� ���� int
Pair Pair::operator+(int constant) {
	return Pair(a + constant, b);
}
//���������� �������� �������� �������� ��� ���� ���� double
Pair Pair::operator+(double constant) {
	return Pair(a, b + constant);
}
Pair Pair::operator+(const Pair& P) {
	Pair temp;
	temp.a = a + P.a;
	temp.b = b + P.b;
	return temp;
}
Pair Pair::operator /(int s) {
	Pair temp;
	temp.a = a / s;
	temp.b = b / s;
	return temp;
}
bool Pair::operator>=(const Pair& P) {
	if (a >= P.a && b >= P.b)
		return 1;
	else
		return 0;
}
bool Pair::operator<=(const Pair& P) {
	if (a <= P.a && b <= P.b)
		return 1;
	else
		return 0;
}
bool Pair::operator>(const Pair& P) {
	double s1 = a + b;
	double s2 = P.a + P.b;
	if (s1 > s2)
		return 1;
	else
		return 0;
}
bool Pair::operator<(const Pair& P) {
	double s1 = a + b;
	double s2 = P.a + P.b;
	if (s1 < s2)
		return 1;
	else
		return 0;
}
//���������� ���������� �������-�������� �����
istream& operator>>(istream& in, Pair& N) {
	cout << "����� �����? "; in >> N.a;
	cout << "������� �����? "; in >> N.b;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Pair& N) {
	return (out << "(" << N.a << " : " << N.b << ")");
}

