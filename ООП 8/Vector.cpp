#include "Vector.h"
#include "MAGAZIN.h"
#include "Event.h"
#include <iostream>
using namespace std;

Vector::Vector() {
	beg = nullptr;
	cur = 0;
	size = 0;
}
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
	beg = 0;
}
//���������� �������, �� ������� ��������� ��������� p � ������
void Vector::Add()
{
	Object* p;
	//����� �� �������� ���� ��������� �������
	cout << "1.�������� �������" << endl;
	cout << "2.������" << endl;
	int y;
	cin >> y;
	if (y == 1) { //���������� ������� ������ PRINT
		PRINT* a = new PRINT;
		a->Input(); //���� �������� ���������
		p = a;
		if (cur < size) {
			beg[cur] = p; //���������� � ������
			cur++;
		}
	}
	else {
		if (y == 2) { //���������� ������� ������ MAGAZIN
			MAGAZIN* b = new MAGAZIN;
			b->Input();
			p = b;
			if (cur < size) {
				beg[cur] = p;
				cur++;
			}
		}
		else
			return;
	}
}
//�������� �������� �� �������
void Vector::Del()
{
	if (cur == 0)
		return;
	cur--;
}
void Vector::Show()
{
	if (cur == 0)
		cout << "������ ������" << endl;
	Object** p = beg; //��������� �� ��������� ���� Object
	for (int i = 0; i < cur; i++) {
		(*p)->Show(); //����� ������ Show()
		p++; //����������� ��������� �� ��������� ������
	}
}
void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e); //����� ������ 
			p++; //����������� ��������� �� ��������� ������
		}
	}
}
//��������, ������� ���������� ������ �������
int Vector::operator ()()
{
	return size;
}
