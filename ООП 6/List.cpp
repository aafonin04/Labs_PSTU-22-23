#include <iostream>
#include "List.h"
using namespace std;

List::List() 
{
	size = 0;
	first = nullptr;
	last = nullptr;
}
List::List(int s)
{
	size = s;
	first = nullptr;
	last = nullptr;
	for (int i = 0; i < size; i++) {
		Node* newNode = new Node;
		newNode->data = rand() % 10;
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
	beg.elem = first;
	end.elem = nullptr;
}

List::List(const List& L) 
{
    size = 0;
    first = nullptr;
    last = nullptr;
    Node* current = L.first;
	while (current != nullptr) {
		Node* newNode = new Node();
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
	beg = L.beg;
	end = L.end;
}
List::~List() 
{
	Node* current = first;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}

}
//Метод для добавления элементов в конец списка
void List::push(int value)
{
	Node* newNode = new Node;
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
void List::pop() {
	if (first == nullptr){
		cout << "Список пустой. Нечего удалять" << endl;
		return;
	}

	if (first == last){
		delete first;
		first = nullptr;
		last = nullptr;
		return;
	}

	Node* secondToLast = first;
	while (secondToLast->next != last)
	{
		secondToLast = secondToLast->next;
	}
	delete last;
	last = secondToLast;
	last->next = nullptr;
	beg.elem = first;
	end.elem = last->next;
}
List& List::operator=(const List& other)
{
	if (this == &other) {
		return *this; // Проверка на самоприсваивание
	}

	// Очищаем текущий список
	while (first != nullptr) {
		Node* temp = first;
		first = first->next;
		delete temp;
	}

	// Копируем элементы из другого списка
	Node* otherCurrent = other.first;
	while (otherCurrent != nullptr) {
		push(otherCurrent->data);
		otherCurrent = otherCurrent->next;
	}

	return *this;
}
//Метод для доступа к элементу по индексу
int& List::operator[](int index)
{
	if (index >= 0 && index < size){
		Node* curr = first;
		for (int i = 0; i < index; i++){
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
int List::operator()() {
	return size;
}
//Метод для умножения элементов списков a[i]*b[i]
List operator*(List& L1, List& L2) 
{
	if (L1.size != L2.size){
		cout << "Размеры списков не совпадают" << endl;
		exit(222);
	}
	List result;
	Node* currA = L1.first;
	Node* currB = L2.first;
	while (currA != nullptr && currB != nullptr){
		int multipliedValue = currA->data * currB->data;
		result.push(multipliedValue);
		currA = currA->next;
		currB = currB->next;
	}
	return result;
}
ostream& operator<<(ostream& out, const List& L) 
{
	if (L.first == nullptr) {
		cout << "Список пустой" << endl;
		return out;
	}
	Node* current = L.first;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
	return out;
}
istream& operator>>(istream& in, List& L)
{
	int count;
	cout << "Введите количество элементов в списке: ";
	in >> count;
	cout << "Введите элементы списка: ";
	for (int i = 0; i < count; i++) {
		int value;
		in >> value;
		L.push(value);
	}
	return in;
}
