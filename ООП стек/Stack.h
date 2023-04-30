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
	void push(string); //Метод для добавления элемента в стек
	void pop(); //Метод для удаления элемента из стека
	void deletekey(string); //Метод для удаления ключа
	void newelem(int); //Метод для удаления элемента перед элементом с заданным номером
	Stack& operator=(const Stack&);
	string& operator[] (int); 
	int operator()(); 
	friend ostream& operator<<(ostream&, const Stack&);
	friend istream& operator>>(istream&, Stack&);
};

