#include <iostream>
#include "Pair.h"
#include <list>
#include <queue>
using namespace std;

typedef priority_queue<Pair>Pq;
typedef list<Pair>List;

Pq make_pq(int n) {
	Pq pq;
	Pair p;
	for (int i = 0; i < n; i++) {
		cin >> p;
		pq.push(p);
	}
	return pq;
}

List copy_pq_to_list(Pq pq) {
	List l;
	while (!pq.empty()) {
		l.push_back(pq.top());
		pq.pop();
	}
	return l;
}

Pq copy_list_to_pq(List l) {
	Pq pq;
	for (auto it = l.begin(); it != l.end(); ++it) {
		pq.push(*it);
	}
	return pq;
}

void print_pq(Pq pq) {
	List l = copy_pq_to_list(pq);
	for (auto it = l.cbegin(); it != l.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void pq_mean(Pq& pq) {
	List l = copy_pq_to_list(pq);
	int n = 1;
	Pair sum = pq.top();
	pq.pop();
	while (!pq.empty()) {
		sum = sum + pq.top();
		pq.pop();
		n++;
	}
	pq = copy_list_to_pq(l);
	Pair mean = sum / n;
	pq.push(mean);
}

void delete_range(Pq& pq) {
	Pair left, right;
	List l = copy_pq_to_list(pq);
	cout << "Введите левую границу диапазона: "; cin >> left;
	cout << "Введите правую границу диапазона: "; cin >> right;
	for (auto i = l.begin(); i != l.end();) {
		if (*i >= left && *i <= right)
			i = l.erase(i);
		else
			i++;
	}
	pq = copy_list_to_pq(l);
}

void max_min(Pq& pq) {
	List l = copy_pq_to_list(pq);
	Pair max = l.front();
	Pair min = l.front();
	for (auto i = l.begin(); i != l.end(); i++) {
		if (*i > max)
			max = *i;
		if (*i < min)
			min = *i;
	}
	Pair sum = max + min;
	for (auto i = l.begin(); i != l.end(); i++) {
		*i = *i + sum;
	}
	pq = copy_list_to_pq(l);
}

int main() {
	setlocale(LC_ALL, "RUS");
	Pq pq;
	int n;
	cout << "Размер очереди? "; cin >> n;
	pq=make_pq(n);
	cout << "Ваша очередь: "; print_pq(pq);
	pq_mean(pq);
	cout << endl << "Список после добавления среднего арифмитического: "; print_pq(pq);
	cout << endl;
	delete_range(pq);
	cout << "Список после удаления элементов: "; print_pq(pq);
	max_min(pq);
	cout << endl << "Список после добавления суммы max и min: "; print_pq(pq);
	return 0;
}