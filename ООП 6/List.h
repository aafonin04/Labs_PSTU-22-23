#pragma once
#include <iostream>
using namespace std;

class Node 
{
public:
	int data = 0;
	Node* next = nullptr;
};

class Iterator 
{
	friend class List;
private:
	Node* elem;
public:
	Iterator() { elem = nullptr; } //Конструктор без параметров
	Iterator(const Iterator& it) { elem = it.elem; } //Конструктор копирования
	//Перегруженные операторы сравнения
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; }
	//Переход вправо к элементу с номером n
	Iterator& operator + (const int& n) {
		for (int i = 0; i < n; i++) {
			if (elem == nullptr) {
				cout << "Ошибка: достигнут конец списка" << endl;
				exit(222);
			}
			elem = elem->next;
		}
		return *this;
	}
	//Перегруженная операция разыменования
	int& operator *() const { return elem->data; }
};

class List
{
private:
	int size;
	Node* first;
	Node* last;
	Iterator beg;
	Iterator end;
public:
	List();
	List(int);
	List(const List&);
	~List();
	void push(int); //Метод для добавления элементов в конец списка
	void pop(); //Метод для удаления элементов
	List& operator=(const List&);
	int& operator[] (int); //Метод для доступа к элементу по индексу 
	int operator()(); //Метод для определения размера списка
	friend List operator*(List&, List&); //Метод для умножения элементов списков a[i]*b[i]
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, List&);
	Iterator f() { return beg; }
	Iterator l() { return end; }

};

