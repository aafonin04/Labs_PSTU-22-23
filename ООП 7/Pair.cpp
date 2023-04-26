#include <iostream>
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
//���������� �������� ������������
Pair& Pair::operator=(const Pair& N) {
	if (&N == this)
		return *this;
	a = N.a;
	b = N.b;
	return *this;
}
//����� ��� ��������� ��������� ������� a[i]*b[i]
Pair operator*(Pair& P1, Pair& P2) {
	Pair result;
	result.a = P1.a * P2.a;
	result.b = P1.b * P2.b;
	return result;
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
