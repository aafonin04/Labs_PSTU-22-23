#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node
{
	string key;
	Node* next;
};

struct LinkedList
{
	Node* head; // указатель на начало списка
	Node* tail; // указатель на конец списка

	// Конструктор
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
};

// Функция для добавления элемента в конец списка
void addNode(LinkedList& list, const string& value)
{
	Node* newNode = new Node;
	newNode->key = value;
	newNode->next = nullptr;

	if (list.head == nullptr) // если список пустой, новый элемент становится головным и хвостовым
	{
		list.head = newNode;
		list.tail = newNode;
	}
	else
	{
		list.tail->next = newNode; // добавляем новый элемент после текущего хвостового элемента
		list.tail = newNode; // обновляем указатель на хвостовой элемент
	}
}

// Функция для вывода списка
void print_list(Node* beg)
{
	if (beg == nullptr) // если список пустой
	{
		cout << "Список пустой" << endl;
		return;
	}

	cout << "Ваш список: ";
	Node* p = beg;
	while (p != nullptr) // пока не конец списка
	{
		cout << p->key << ' ';
		p = p->next; // перейти на следующий элемент
	}
	cout << endl;
}

// Функция для удаления узла 
Node* del_Node(Node* beg, int k)
{
	setlocale(LC_ALL, "RUS");
	k--;
	Node* p = beg;

	if (k == 0)
	{
		beg = beg->next;
		if (beg == nullptr) return nullptr;
		delete p;
		return beg;
	}

	for (int i = 0; i < k - 1 && p != nullptr; i++, p = p->next);

	if (p == nullptr || p->next == nullptr) return beg;

	Node* r = p->next; // встать на удаляемый элемент
	p->next = r->next; // изменить ссылку
	delete r;
	r = p->next; // встать на следующий
	return beg;
}

// Функция для добавления элементов слева и справа от ключевого слова
void add_Node(LinkedList& list, int k, const string& value)
{
	setlocale(LC_ALL, "RUS");
	k--;

	Node* p = new Node;
	p->key = value;

	if (k == 0)
	{
		p->next = list.head; // добавить перед головным элементом
		list.head = p; // обновить указатель на головной элемент
		return;
	}

	Node* r = list.head; // встать на начало списка
	for (int i = 0; i < k - 1 && r->next != nullptr; i++, r = r->next);
	p->next = r->next; // связать r с концом списка

	// если элемент не последний, то связать конец списка с r
	if (r->next == nullptr) p->next = nullptr;
	r->next = p;
}

int find_key_index(Node* beg)
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите ключевое слово: ";
	string key_word;
	cin >> key_word;
	Node* r = beg;
	int counter = 1;
	while (r != nullptr)
	{
		if (r->key == key_word)
			return counter;
		r = r->next;
		counter++;
	}
	cout << "Такое ключевое слово не найдено" << endl;
	return -1; // возвращаем -1 для обозначения отсутствия найденного ключевого слова
}

Node* delete_list(Node* beg)
{
	setlocale(LC_ALL, "RUS");
	Node* p = beg;
	int counter = 0; // Изменяем начальное значение counter на 0
	while (p != nullptr) // Изменяем условие цикла на p != nullptr
	{
		p = p->next;
		counter++;
	}
	for (int i = counter; i > 1; i--) 
	{
		beg = del_Node(beg, i); // Используем функцию del_Node() для удаления узлов 
	}
	beg = del_Node(beg, 1); // Удаляем первый узел
	return beg;
}

void printINfile(Node* beg, string path) {
	setlocale(LC_ALL, "RUS");
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		cout << "Ошибка" << endl;
	}
	else {
		cout << "Информация добавлена в файл" << endl;
		Node* p = beg;
		while (p != nullptr) {
			fout << p->key;
			fout << "\n";
			p = p->next;
		}
	}
	fout.close();
}

//Функция для восстановления списка из файла
Node* readFROMfile(string path) {
	setlocale(LC_ALL, "RUS");
	ifstream fin;
	fin.open(path);
	Node* beg = nullptr; 
	if (!fin.is_open()) {
		cout << "Ошибка" << endl;
	}
	else {
		cout << "Информация была восстановлена из файла" << endl;
		string word;
		Node* p = nullptr; 
		Node* r = nullptr; 
		fin >> word;
		while (!fin.eof()) { 
			if (p == nullptr) {
				p = new(Node);
				p->key = word;
				p->next = nullptr;
				beg = p;
			}
			else {
				r = new(Node);
				r->key = word;
				p->next = r;
				r->next = nullptr;
				p = r;
			}
			fin >> word;
		}
	}
	fin.close();
	return beg;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int c;
	string value;
	LinkedList list; // Создаем экземпляр связного списка
	cout << "Введите количество элементов списка: "; cin >> c;
	for (int i = 1; i <= c; i++) {
		cout << "Введите элемент спика: "; cin >> value;
		addNode(list, value);
	}

	Node* first = list.head; // Устанавливаем начало списка на головной элемент
	print_list(first); // Выводим список на экран

	cout << "Номер элемента, который вы хотите удалить: ";
	int n;
	cin >> n;

	first = del_Node(first, n); // Удаляем элемент из списка
	print_list(first); // Выводим обновленный список на экран

	int num = find_key_index(first); // Ищем индекс ключевого слова в списке

	cout << "Введите количество, добавляемых слева и справа элементов: ";
	int k;
	string add;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cout << "Введите добавлемяый элемент: "; cin >> add;
		add_Node(list, num + i, add); // Добавляем элементы слева от ключевого слова
	}
	num += k;
	for (int i = 0; i < k; i++) {
		cout << "Введите добавлемяый элемент: "; cin >> add;
		add_Node(list, num + i + 1,add); // Добавляем элементы справа от ключевого слова
	}
	print_list(list.head); // Выводим обновленный список на экран
	cout << endl;
	printINfile(first, "output.txt");
	list.head = delete_list(first);
	cout << "Список удалён: "; print_list(list.head);
	Node* recovery = readFROMfile("output.txt");
	list.head = recovery;
	print_list(list.head);
	return 0;
}