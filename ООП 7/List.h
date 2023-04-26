#pragma once
#include <iostream>
using namespace std;

template <typename type>
class Node
{
public:
	type data;
	Node<type>* next;
	Node(): data(type()), next(nullptr) {}
	Node(const type& value) {
		data = value;
		next = nullptr;
	}
};

template <typename type>
class List
{
private:
	int size;
	Node<type>* first;
	Node<type>* last;
public:
	List();
	List(int, type);
	List(const List&);
	~List();
	void push(const type&); //Метод для добавления элементов в конец списка
	void pop(); //Метод для удаления элементов
	List<type>& operator=(const List&);
	type& operator[] (int); //Метод для доступа к элементу по индексу 
	int operator()(); //Метод для определения размера списка
	//Метод для умножения элементов списков a[i]*b[i]
	friend List<type> operator*(List<type>& L1, List<type>& L2) {
		if (L1.size != L2.size) {
			cout << "Размеры списков не совпадают" << endl;
			exit(222);
		}
		List<type> result;
		Node<type>* currA = L1.first;
		Node<type>* currB = L2.first;
		while (currA != nullptr && currB != nullptr) {
			type multipliedValue = currA->data * currB->data;
			result.push(multipliedValue);
			currA = currA->next;
			currB = currB->next;
		}
		return result;
	}
	friend ostream& operator<<(ostream& out, const List<type>& L)
	{
		if (L.first == nullptr) {
			out << "Список пустой" << endl;
			return out;
		}
		Node<type>* current = L.first;
		while (current != nullptr) {
			out << '[' << current->data << ']' << " ";
			current = current->next;
		}
		cout << endl;
		return out;
	}

	friend istream& operator>>(istream& in, List<type>& L)
	{
		int count;
		cout << "Введите количество элементов в списке: ";
		in >> count;
		cout << "Введите элементы списка: ";
		for (int i = 0; i < count; i++) {
			type value;
			in >> value;
			L.push(value);
		}
		return in;
	}
};


