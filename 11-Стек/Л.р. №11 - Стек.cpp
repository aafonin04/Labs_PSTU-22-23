#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// Определение узла стека
struct Node {
    string data; // Данные одного узла
    Node* next; // Указатель на следующий узел
};

// Определение структуры стека
struct Stack {
    Node* top; // Указатель на вершину стека
    Stack() {
        top = nullptr;
    }
};

// Функция добавления элемента в стек
void push(Stack& stack, string value) {
    Node* newNode = new Node; // Создание нового узла стека
    newNode->data = value;
    newNode->next = stack.top;
    stack.top = newNode; // Обновление вершины стека
    delete newNode;
}

// Функция удаления элемента из стека
void pop(Stack& stack) {
    if (stack.top == nullptr) {
        cout << "Стэк пустой" << endl; // Стек пуст, невозможно удалить элемент
    }
    else {
        Node* nodeToRemove = stack.top; // Сохранение указателя на удаляемый узел
        stack.top = stack.top->next; // Обновление вершины стека
        delete nodeToRemove; // Удаление узла стека
    }
}

// Функция вывода содержимого стека
void printStack(const Stack& stack) {
    Node* current = stack.top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//Функция для копирования элементов в промежуточный стек для 1-го задания
void copy_stack1(Stack& source, Stack& destination) {
    while (source.top != nullptr) {
        printStack(destination);
        push(destination, source.top->data); // Копирование значени элемента в новый стек
        source.top = source.top->next; // Переход к следующему элементу в старом стеке
    }
}

//Функция для копирования элементов в промежуточный стек для 2-го задания
void copy_stack2(Stack& source, Stack& destination) {
    while (source.top != nullptr) {
        push(destination, source.top->data); // Копирование значени элемента в новый стек
        source.top = source.top->next; // Переход к следующему элементу в старом стеке
    }
}

//Функция для удаления ключа
void delete_key(Stack& stack, Stack& stack1, string key) {
    while (stack.top->data != key) {
        printStack(stack);
        push(stack1, stack.top->data);
        pop(stack);
    }
    printStack(stack);
    pop(stack);
    printStack(stack);
}

//Функция для удаления элемента перед элементом с заданным номером
void delete_elem(Stack& stack, Stack& stack1, int n) {
    for (int i = 0; i <n-1; i++) {
        push(stack1, stack.top->data);
        pop(stack);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stack stack, stack1, stack3;
    string a, s, el;
    int n, m, k;
    cout << "Введите количество элементов в стеке: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент стека: "; cin >> a;
        push(stack, a);
    }
    cout << endl << "Ваш стек: "; 
    printStack(stack);
    cout << endl << "Введите ключ удаления: "; cin >> s;
    delete_key(stack, stack1, s);
    cout << endl << "Промежуточный стек: "; 
    printStack(stack1);
    cout << endl;
    copy_stack1(stack1, stack);
    cout << "Стэк после удления элемнта: "; printStack(stack);
    cout << endl << "Введите номер элемента, перед которым нужно вставить новые элементы стека: ";  cin >> m;
    delete_elem(stack, stack3, m);
    cout << "Введите количество добавляемых элементов: "; cin >> k;
    for (int i = 1; i <= k; i++) {
        cout << "Введиет добавляемый элемент: "; cin >> el;
        push(stack, el);
    }
    copy_stack2(stack3, stack);
    cout << "Стек после добавления элементов: ";
    printStack(stack);
    cout << endl;
    cout << "Удаление элементов стека:" << endl;
    for (int i = 0; i < n; i++) {
        printStack(stack);
        pop(stack);
    }
    printStack(stack);
    cout << endl;
    return 0;
}
