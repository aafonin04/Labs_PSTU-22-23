#pragma once
#include <iostream>
#include <set>
using namespace std;

template <typename type>
class List
{
private:
	multiset<type>m;
	int size = 0;
public:
	List();
	List(int);
	List(int, type);
	~List();
	void Print();
	void List_mean();
	void Delete_range();
	void Max_min();
};

template <typename type>
List<type>::List() {
	size = 0;
}

template <typename type>
List<type>::List(int n) {
	type data; 
	size = n;
	for (int i = 0; i < n; ++i) {
		cout << "¬ведите значение: ";
		cin >> data;
		m.insert(data);
	}
}

template <typename type>
List<type>::List(int n, type k) {
	size = n;
	for (int i = 0; i < n; ++i) {
		m.insert(k);
	}
}

template <typename type>
List<type>::~List() {}

template <typename type>
void List<type>::Print() {
	for (type elem : m) cout << elem << endl;
}


template <typename type>
void List<type>::List_mean() {
	double s = 0;
	for (auto& it : m) s += it;
	cout << "—рднее арифметическое: " << s / size << endl;
	m.insert(s / size);
}

template <typename type>
void List<type>::Delete_range() {
	type left, right;
	cout << "¬ведите левую границу диапазона: "; cin >> left;
	cout << "¬ведите правую границу диапазона: "; cin >> right;
	auto be = m.lower_bound(left);
	auto en = m.upper_bound(right);
	m.erase(be, en);
}

template <typename type>
void List<type>::Max_min() {
	auto mini = m.begin();
	auto maxi = --m.end();
	cout << "min: " << *mini << endl;
	cout << "max: " << *maxi << endl;
	type sum = *mini; sum += (*maxi);
	cout << "—умма = " << sum << endl;
	multiset<type> m1;
	for (auto t = m.begin(); t != m.end(); t++) {
		type temp = *t;
		temp += sum;
		m1.insert(temp);
	}
	m = m1;
}