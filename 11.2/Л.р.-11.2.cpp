#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct point
{
	string key;
	point* prev, * next;
};

point* make_list()
{
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "Введите размер списка: ";
	cin >> n;
	cout << "Введите элемент списка: ";
	string s;
	cin >> s;

	point* p, * r, * beg;
	p = new (point);
	p->key = s;
	p->prev = nullptr;
	p->next = nullptr;
	beg = p;

	for (int i = 1; i < n; i++) //добавить элементы в конец списка
	{
		r = new(point);
		cout << "Введите элемент списка: ";
		string s;
		cin >> s;

		r->key = s;
		p->next = r;
		r->prev = p;
		r->next = nullptr;
		p = r;
	}
	return beg;
}

void print_list(point* beg)
{
	setlocale(LC_ALL, "RUS");
	if (beg == nullptr) //если список пустой
	{
		cout << "Список пустой" << endl;
		return;
	}
	cout << "Ваш список: ";
	point* p = beg;
	while (p != nullptr) //пока не конец списка
	{
		cout << p->key << ' ';
		p = p->next; //перейти на следующий элемент
	}
	cout << "\n";
}

point* del_point(point* beg, int k)
{
	k--;
	point* p = beg;
	if (k == 0) {
		beg = beg->next;
		if (beg == nullptr) {
			return nullptr;
		}
		beg->prev = nullptr;
		delete p;
		return beg;
	}
	for (int i = 0; i < k - 1 && p != nullptr; i++, p = p->next);
	if (p == nullptr || p->next == nullptr) return beg;
	point* r = p->next; //встать на удаляемый элемент
	p->next = r->next; //изменить ссылку
	delete r;
	r = p->next; //встать на следующий
	//если r существует, то связать элементы
	if (r) r->prev = p;
	return beg;
}

point* add_point(point* beg, int k)
{
	setlocale(LC_ALL, "RUS");
	k--;
	point* p;
	p = new(point);
	cout << "Введите новый элемент списка: ";
	string s;
	cin >> s;
	p->key = s;
	if (k == 0)
	{
		p->next = beg; //добавить перед beg
		p->prev = nullptr; //обнулить адрес предыдущего
		//связать список с добавленным элементом
		beg->prev = p;
		beg = p; //запомнить первый элемент в beg
		return beg;
	}
	point* r = beg; //встать на начало списка
	for (int i = 0; i < k - 1 && r->next != nullptr; i++, r = r->next);
	p->next = r->next; //связать р с концом списка
	//если элемент не последний, то связать конец списка с р
	if (r->next != nullptr) r->next->prev = p;
	p->prev = r; //связать р и r
	r->next = p;
	return beg;
}

int find_key_index(point* beg) {
	setlocale(LC_ALL, "RUS");
	cout << "Введите ключевое слово: ";
	string key_word;
	cin >> key_word;
	point* r = beg;
	int counter = 1;
	while (r) {
		if (r->key == key_word) return counter;
		r = r->next;
		counter++;
	}
	cout << "Такое ключевое слово не найдено" << endl;
	return NULL;
}

point* delete_list(point* beg) {
	setlocale(LC_ALL, "RUS");
	point* p = beg;
	int counter = 1;
	while (p->next != nullptr) {
		p = p->next;
		counter++;
	}
	for (int i = counter; i > 0; i--) {
		beg = del_point(beg, i);
	}
	return beg;
}

void printINfile(point* beg, string path) {
	setlocale(LC_ALL, "RUS");
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) { cout <<  "Ошибка" << endl; }
	else {
		cout << "Информация добавлена в файл" << endl;
		point* p = beg;
		while (p != nullptr) {
			fout << p->key;
			fout << "\n";
			p = p->next;
		}
	}
	fout.close();
}

point* readFROMfile(string path) {
	setlocale(LC_ALL, "RUS");
	ifstream fin;
	fin.open(path);
	point* beg = new(point);
	if (!fin.is_open()) { cout << "Ошибка" << endl; }
	else {
		cout << "Информация была восстановлена из файла" << endl;
		string word;
		point* p, * r;
		p = new (point);
		fin >> word;
		p->key = word;
		p->prev = nullptr;
		p->next = nullptr;
		beg = p;

		while (!fin.eof()) { //eof = end of file
			word = "";
			fin >> word;
			r = new(point);
			r->key = word;
			p->next = r;
			r->prev = p;
			r->next = nullptr;
			p = r;
		}
	}
	fin.close();
	return beg;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleCP(1251);
	point* first = make_list();
	print_list(first);

	cout << "Номер элемента, который вы хотите удалить: ";
	int n;
	cin >> n;

	first = del_point(first, n);
	print_list(first);

	int num = find_key_index(first);

	cout << "Введите количество, добавляемых слева и справа элементов: ";
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		first = add_point(first, num + i);
	}
	num += k;
	for (int i = 0; i < k; i++) {
		first = add_point(first, num + i + 1);
	}
	print_list(first);

	string path = "myFile.txt";
	printINfile(first, path);
	first = delete_list(first);
	print_list(first);

	point* second = readFROMfile(path);
	print_list(second);

	return 0;
}