#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef list<double>List;

List make_list(int n) {
	List L;
	for (int i = 0; i < n; i++) {
		double a = (rand() % 101 - 50) / 10.0;
		L.push_back(a);
	}
	return L;
}

void print(List& L) {
	for (auto i = L.begin(); i != L.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

void list_mean(List& L) {
	double sum = 0;
	for (auto i = L.begin(); i != L.end(); ++i) {
		sum += *i;
	}
	int size = L.size();
	double mean = sum / size;
	L.push_back(mean);
}

void delete_range(List& L) {
	double left, right;
	cout << "Введите левую границу диапазона: "; cin >> left;
	cout << "Введите правую границу диапазона: "; cin >> right;
	for (auto i = L.begin(); i != L.end();) {
		if (*i >= left && *i <= right)
			i = L.erase(i);
		else
			++i;
	}
}

void max_min(List& L) {
	double max = L.front();
	double min = L.front();
	for (auto i = L.begin(); i != L.end(); ++i) {
		if (*i > max)
			max = *i;
		if (*i < min)
			min = *i;
	}
	double sum = max + min;
	for (auto i = L.begin(); i != L.end(); ++i) {
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