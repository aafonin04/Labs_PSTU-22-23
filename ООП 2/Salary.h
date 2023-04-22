#pragma once
#include <iostream>
#include <string>
using namespace std;

class Salary
{
private:
	string name; //���
	double pay; //�����
	int bonus; //������ (% �� ������)
public:
	Salary(); //����������� ��� ����������
	Salary(string, double, int); //����������� � �����������
	Salary(const Salary&); //����������� �����������
	~Salary(); //����������
	string get_name(); //�������� ���� name
	void set_name(string); //���������� ���� name
	double get_pay(); //�������� ���� pay
	void set_pay(double); //����������� ���� pay
	int get_bonus(); //�������� ���� bonus
	void set_bonus(int); //����������� ���� bonus
	void show(); //�������� �����
};

