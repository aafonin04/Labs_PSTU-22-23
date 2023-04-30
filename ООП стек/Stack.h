#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
	string data;
	Node* next;
};

class Stack
{
private:
	int size;
	Node* top;
public:
	Stack();
	Stack(int, string);
	Stack(const Stack&);
	~Stack();
	void push(string); //����� ��� ���������� �������� � ����
	void pop(); //����� ��� �������� �������� �� �����
	void deletekey(string); //����� ��� �������� �����
	void newelem(int); //����� ��� �������� �������� ����� ��������� � �������� �������
	Stack& operator=(const Stack&);
	string& operator[] (int); 
	int operator()(); 
	friend ostream& operator<<(ostream&, const Stack&);
	friend istream& operator>>(istream&, Stack&);
};

