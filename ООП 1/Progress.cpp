#include <iostream>
#include "Progress.h"
using namespace std;

void Progress::Init(double F, int S) { //���������� ������ ��� ������������� ����� ������
	first = F;
	second = S;
}

void Progress::Read() { //���������� ������ ��� ������ �������� ����� ������
	cout << "������ ������� ����������: "; cin >> first;
	cout << "���������� ��������� ����������: "; cin >> second;
}

void Progress::Show() { //���������� ������ ��� ������ �������� ����� ������
	cout << "������ ������� ���������: " << first << endl;
	cout << "���������� ��������� ����������: " << second << endl;
}

double Progress::Element(int j) { //���������� ������ ���������� j-�� ��������
	return first * pow(second, j-1);
}
