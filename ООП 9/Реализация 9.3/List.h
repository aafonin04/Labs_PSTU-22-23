#pragma once
#include <iostream>
using namespace std;
const int Max_size = 10; //Максимальный размер списка

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
	void push(int); //Метод для добавления элементов в конец списка
	void pop(); //Метод для удаления элементов
	void shift(int); //Метод для перехода к элементу с номером n
	List& operator=(const List&);
	int& operator[] (int); //Метод для доступа к элементу по индексу 
	int operator()(); //Метод для определения размера списка
	friend List operator*(List&, List&); //Метод для умножения элементов списков a[i]*b[i]
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, List&);
};