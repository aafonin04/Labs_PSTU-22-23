#include "List.h"
#include <iostream>
using namespace std;

template <typename type>
List<type>::List() {
	size = 0;
	first = nullptr;
	last = nullptr;
}
template <typename type>
List<type>::List(int s, type d) {
	size = s;
	first = nullptr;
	last = nullptr;
	for (int i = 0; i < size; i++) {
		Node<type>* newNode = new Node<type>;
		newNode->data = d;
		if (last == nullptr) {
			first = newNode;
			last = newNode;
		}
		else {
			if (last != nullptr) {
				last->next = newNode;
				last = newNode;
			}
		}
	}
}
template <typename type>
List<type>::List(const List<type>& L) {
	size = 0;
	first = nullptr;
	last = nullptr;
	Node<type>* current = L.first;
	while (current != nullptr) {
		Node<type>* newNode = new Node<type>();
		newNode->data = current->data;
		newNode->next = nullptr;
		if (last == nullptr) {
			first = newNode;
			last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
		current = current->next;
		size++;
	}
}
template <typename type>
List<type>::~List() 
{
	Node<type>* current = first;
	while (current != nullptr) {
		Node<type>* next = current->next;
		delete current;
		current = next;
	}
}
//Метод для добавления элементов в конец списка
template <typename type>
void List<type>::push(const type& value)
{
	Node<type>* newNode = new Node<type>;
	newNode->data = value;
	newNode->next = nullptr;
	if (first == nullptr)
	{
		first = newNode;
		last = newNode;
		size++;
	}
	else
	{
		last->next = newNode;
		last = newNode;
		size++;
	}
}
//Метод для удаления элементов
template <typename type>
void List<type>::pop() {
	if (first == nullptr) {
		cout << "Список пустой. Нечего удалять" << endl;
		return;
	}

	if (first == last) {
		delete first;
		first = nullptr;
		last = nullptr;
		return;
	}

	Node<type>* secondToLast = first;
	while (secondToLast->next != last)
	{
		secondToLast = secondToLast->next;
	}
	delete last;
	last = secondToLast;
	last->next = nullptr;
}
template <typename type>
List<type>& List<type>::operator=(const List<type>& L)
{
	if (this == &L) {
		return *this; // Проверка на самоприсваивание
	}
	// Очищаем текущий список
	while (first != nullptr) {
		Node<type>* temp = first;
		first = first->next;
		delete temp;
	}
	// Копируем элементы из другого списка
	Node<type>* otherCurrent = L.first;
	while (otherCurrent != nullptr) {
		push(otherCurrent->data);
		otherCurrent = otherCurrent->next;
	}
	return *this;
}
//Метод для доступа к элементу по индексу
template <typename type>
type& List<type>::operator[](int index)
{
	if (index >= 0 && index < size) {
		Node<type>* curr = first;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr->data;
	}
	else {
		cout << "Элемент находится за пределами списка" << endl;
		exit(222);
	}
}
//Метод для определения размера списка
template <typename type>
int List<type>::operator()() {
	return size;
}