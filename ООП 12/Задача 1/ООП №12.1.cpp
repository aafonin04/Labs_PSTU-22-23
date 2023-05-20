#include <iostream>
#include <set>
#include <ctime>
using namespace std;
typedef multiset<double> TMS; 
typedef TMS::iterator it; 

TMS make_set(int n) {
	srand(time(NULL));
	TMS m; double a;
	for (int i = 0; i < n; i++) {
		a = round(((double)(rand()) / RAND_MAX * 10 + 1) * 100) / 100;
		m.insert(a);
	}
	return m;
}

void print_TMS(TMS m) {
	int k = 1;
	for (it i = m.begin(); i != m.end(); i++) cout << k++ << ") " << *i << " " << endl;
}

double mean(TMS& m) {
	double s = 0, n = m.size();
	for (it i = m.begin(); i != m.end(); i++) s += *i;
	s = (round(((double)(s / n) * 100) / 100));
	m.insert(s);
	return s;
}

void add_minmax(TMS& m) {
	it i = m.begin();
	double cur_max = *i, cur_min = *i;
	for (; i != m.end(); i++) {
		if (cur_max < *i) cur_max = *i;
		if (cur_min > *i) cur_min = *i;
	}
	TMS m1;
	for (it t = m.begin(); t != m.end(); t++) {
		double temp = *t + cur_min + cur_max;
		m1.insert(temp);
	}
	m = m1;
}

void range(TMS& m) {
	int one, two;
	cout << "\nВведите левую границу: "; cin >> one;
	cout << "\nВведите правую границу: "; cin >> two;
	if (one > two) swap(one, two);

	// Проверка наличия введенных значений в множестве
	if (m.empty() || one > *m.rbegin() || two < *m.begin()) {
		cout << "Введенные значения не принадлежат диапазону множества." << endl;
		return;
	}

	it first = m.lower_bound(one);
	it last = m.upper_bound(two);

	TMS m1;
	for (double elem : m) {
		if (!(elem > *first && elem < *last)) {
			m1.insert(elem);
		}
	}
	m = m1;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "Введите размер множества: "; cin >> n;
	TMS m = make_set(n);
	print_TMS(m);
	cout << "\nДобавление среднего арифметического (" << mean(m) << ")\n"; print_TMS(m);
	cout << "\nУдаление из диапазона\n"; range(m); print_TMS(m);
	cout << "\nДобавление ко всем элементов суммы максимального и минимального элементов\n"; add_minmax(m); print_TMS(m);
	return 0;
}