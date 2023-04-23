#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string name;
	int age;
public:
	//������������� � ����������
	Person();
	Person(string, int);
	Person(const Person&);
	~Person();
	//������ � ������ ��� ���� name
	string get_name();
	void set_name(string);
	//������ � ������ ��� ���� age
	int get_age();
	void set_age(int);
	//���������� ��������� ������������
	Person& operator=(const Person&);
	//���������� ��������� ������� ��� �����/������
	friend istream& operator>>(istream& in, Person&);
	friend ostream& operator<<(ostream& out, const Person&);
};

