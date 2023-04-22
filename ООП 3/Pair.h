#include <iostream>
using namespace std;
#pragma once

class Pair {
private:
	int a;
	double b;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	int get_a();
	void set_a(int);
	double get_b();
	void set_b(double);
	//������������� ��������
	Pair& operator=(const Pair&); //������������
	Pair operator-(const Pair&); //���������
	Pair operator+(int); //�������� (����� �����)
	Pair operator+(double); //�������� (������� �����)
	//���������� ���������� �����/������
	friend istream& operator>>(istream& in, Pair& N);
	friend ostream& operator<<(ostream& out, const Pair& N);
};

