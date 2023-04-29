#pragma once
#include <iostream>
using namespace std;
const int Max_size = 10; //������������ ������ ������

class Node
{
public:
	int data = 0;
	Node* next = nullptr;
};

class List
{
private:
	int size;
	Node* first;
	Node* last;
public:
	List();
	List(int);
	List(const List&);
	~List();
	void push(int); //����� ��� ���������� ��������� � ����� ������
	void pop(); //����� ��� �������� ���������
	void shift(int); //����� ��� �������� � �������� � ������� n
	List& operator=(const List&);
	int& operator[] (int); //����� ��� ������� � �������� �� ������� 
	int operator()(); //����� ��� ����������� ������� ������
	friend List operator*(List&, List&); //����� ��� ��������� ��������� ������� a[i]*b[i]
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, List&);
};