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
	//������������� ��������
	Pair& operator=(const Pair&); //������������
	friend Pair operator*(Pair&, Pair&);
	//���������� ���������� �����/������
	friend istream& operator>>(istream& in, Pair& N);
	friend ostream& operator<<(ostream& out, const Pair& N);
};

