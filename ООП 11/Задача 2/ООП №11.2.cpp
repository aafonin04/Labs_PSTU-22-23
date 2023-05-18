#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Pair.h"
using namespace std;

typedef list<Pair>List;

List make_list(int n) {
	List L;
	Pair p;
	for (int i = 0; i < n; i++) {
		p.random();
		L.push_back(p);
	}
	return L;
}

void print(List& L) {
	for (auto i = L.begin(); i != L.end(); i++) {
		cout << *i << ' ';
	}
	cout << endl;
}

void list_mean(List& L) {
	Pair sum;
	for (auto i = L.begin(); i != L.end(); i++) {
		sum = sum + *i;
	}
	int size = L.size();
	Pair mean = sum / size;
	L.push_back(mean);
}

void delete_range(List& L) {
	Pair left, right;
	cout << "Введите левую границу диапазона: "; cin >> left;
	cout << "Введите правую границу диапазона: "; cin >> right;
	for (auto i = L.begin(); i != L.end();) {
		if (*i >= left && *i <= right)
			i = L.erase(i);
		else
			i++;
	}
}

void max_min(List& L) {
	Pair max = L.front();
	Pair min = L.front();
	for (auto i = L.begin(); i != L.end(); i++) {
		if (*i > max)
			max = *i;
		if (*i < min)
			min = *i;
	}
	Pair sum = max + min;
	for (auto i = L.begin(); i != L.end(); i++) {
		*i = *i + sum;
	}
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	List l;
	int n;
	cout << "Размер списка? "; cin >> n;
	l = make_list(n);
	cout << "Ваш список: "; print(l);
	list_mean(l);
	cout << endl << "Список после добавления среднего арифмитического: "; print(l);
	cout << endl;
	delete_range(l);
	cout << "Список после удаления элементов: "; print(l);
	max_min(l);
	cout << endl << "Список после добавления суммы max и min: "; print(l);
	return 0;
}