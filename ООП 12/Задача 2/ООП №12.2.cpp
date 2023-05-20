#include <iostream>
#include <set>
#include "Pair.h"
using namespace std;
typedef multiset<Pair> TMS; 
typedef TMS::iterator it; 

TMS make_set(int n) {
	srand(time(NULL));
	TMS m; Pair a;
	for (int i = 0; i < n; i++) {
		a.random();
		m.insert(a);
	}
	return m;
}

void print_TMS(TMS m) {
	int k = 1;
	for (it i = m.begin(); i != m.end(); i++) cout << k++ << " : " << *i << " " << endl;
}

Pair mean(TMS& m) {
	Pair sum;
	int n = m.size();
	for (it i = m.begin(); i != m.end(); i++) sum = sum + (*i);
	sum.set_a(sum.get_a() / m.size());
	sum.set_b(round((double)(sum.get_b() / m.size()) * 100) / 100);
	m.insert(sum);
	return sum;
}

void add_minmax(TMS& m) {
	auto mini = m.begin();
	auto maxi = --m.end();
	cout << "min: " << *mini << endl;
	cout << "max: " << *maxi << endl;
	Pair sum;
	sum =sum+ (*mini); sum =sum+ (*maxi);
	cout << "Сумма = " << sum << endl;
	TMS m1;
	for (it t = m.begin(); t != m.end(); t++) {
		Pair temp = *t;
		temp =temp+ sum;
		m1.insert(temp);
	}
	m = m1;
}

void range(TMS& m) {
	double one, two;
	cout << "\nВведите левую границу: "; cin >> one;
	cout << "\nВведите правую границу: "; cin >> two;
	if (one > two) swap(one, two);
	it first = m.end(), last = m.end();
	for (it i = m.begin(); i != m.end(); i++) {
		if (i->get_a() > one) { first = i; break; }
	}
	for (it i = m.begin(); i != m.end(); i++) {
		if (i->get_a() > two) { last = i; break; }
	}
	TMS m1;
	for (Pair elem : m) {
		if (!(elem > *first && *last > elem)) {
			m1.insert(elem);
		}
	}
	m = m1;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "Введите размер: "; cin >> n;
	TMS m = make_set(n);
	print_TMS(m);
	cout << "\nСреднее арифметическое (" << mean(m) << ")\n"; print_TMS(m);
	cout << "\nУдаление значений из диапазона\n"; range(m); print_TMS(m);
	cout << "\nДобавление суммы максимального и минимального ко всем элементам\n"; add_minmax(m); print_TMS(m);
	return 0;
}