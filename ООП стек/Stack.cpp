#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

Stack::Stack()
{
	size = 0;
	top = nullptr;
}
Stack::Stack(int s, string value)
{
	size = s;
	top = nullptr;
	for (int i = 0; i < size; i++) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = top;
		top = newNode;
	}
}
Stack::Stack(const Stack& S)
{
    size = S.size;
    if (S.top == nullptr) {
        top = nullptr;
        return;
    }
    top = new Node;
    top->data = S.top->data;
    Node* current = S.top->next;
    Node* newCurrent = top;
    while (current != nullptr) {
        Node* newNode = new Node;
        newNode->data = current->data;
        newCurrent->next = newNode;
        newCurrent = newNode;
        current = current->next;
    }
    newCurrent->next = nullptr;
}
Stack::~Stack() {
    while (top != nullptr) {
        Node* nodeToRemove = top; // Сохранение указателя на удаляемый узел
        top = top->next; // Обновление вершины стека
        delete nodeToRemove; // Удаление узла стека
    }
}
void Stack::push(string value)
{
    Node* newNode = new Node; // Создание нового узла стека
    newNode->data = value;
    newNode->next = top;
    top = newNode; // Обновление вершины стека
    size++;
}
void Stack:: pop() 
{
    if (top == nullptr) {
        cout << "Стек пустой" << endl; // Стек пуст, невозможно удалить элемент
        return;
    }
    else {
        Node* nodeToRemove = top; // Сохранение указателя на удаляемый узел
        top = top->next; // Обновление вершины стека
        delete nodeToRemove; // Удаление узла стека
        size--;
    }
}
void Stack::deletekey(string key) 
{
    Stack temp;
    while (top->data != key) {
        temp.push(top->data);
        pop();
    }
    pop();
    while (temp.top != nullptr) {
        push(temp.top->data); // Копирование значени элемента в новый стек
        temp.top = temp.top->next; // Переход к следующему элементу в старом стеке
    }
}
void Stack:: newelem(int n) {
    Stack temp;
    for (int i = 0; i < n - 1; i++) {
        temp.push(top->data);
        pop();
    }
    string el;
    int k;
    cout << "Введите количество добавляемых элементов: "; cin >> k;
    for (int i = 1; i <= k; i++) {
        cout << "Введите добавляемый элемент: "; cin >> el;
        push(el);
    }
    while (temp.top != nullptr) {
        push(temp.top->data); // Копирование значени элемента в новый стек
        temp.top = temp.top->next; // Переход к следующему элементу в старом стеке
    }
}
Stack& Stack::operator=(const Stack& S)
{
    if (this == &S) {
        return *this; // Проверка на самоприсваивание
    }
    // Очищаем текущий список
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    // Копируем элементы из другого списка
    Node* otherCurrent = S.top;
    while (otherCurrent != nullptr) {
        push(otherCurrent->data);
        otherCurrent = otherCurrent->next;
    }
    return *this;
}
string& Stack::operator[](int index) {
    if (index >= 0 && index < size) {
        Node* curr = top;
        int i = size - 1; 
        while (i != index) {
            curr = curr->next;
            i--;
        }
        return curr->data;
    }
    else {
        cout << "Элемент находится за пределами стека" << endl;
        exit(222);
    }
}
int Stack::operator()() 
{
    return size;
}
ostream& operator<<(ostream& os, const Stack& S) {
    Node* current = S.top;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}
istream& operator>>(istream& in, Stack& s)
{
    int count;
    cout << "Введите количество элементов в стеке: ";
    in >> count;
    cout << "Введите элементы стека: ";
    for (int i = 0; i < count; i++) {
        string value;
        in >> value;
        s.push(value);
    }
    return in;
}