#pragma once
#include <iostream>
#include <list>
using namespace std;

template <typename type>
class List
{
private:
	list<type>l;
	int size = l.size();
public:
	List();
	List(int);
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
	type a;
	size = n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		l.push_back(a);
	}
}

template <typename type>
List<type>::~List(){}

template <typename type>
void List<type>::Print() {
	for (auto i = l.begin(); i != l.end(); i++) {
		cout << *i << ' ';
	}
	cout << endl;
}

template <typename type>
void List<type>::List_mean() {
	type sum;
	for (auto i = l.begin(); i != l.end(); i++) {
		sum = sum + *i;
	}
	size = l.size();
	type mean = sum / size;
	l.push_back(mean);
}

template <typename type>
void List<type>::Delete_range() {
	type left, right;
	cout << "¬ведите левую границу диапазона: "; cin >> left;
	cout << "¬ведите правую границу диапазона: "; cin >> right;
	for (auto i = l.begin(); i != l.end();) {
		if (*i >= left && *i <= right)
			i = l.erase(i);
		else
			i++;
	}
}

template <typename type>
void List<type>::Max_min() {
	type max = l.front();
	type min = l.front();
	for (auto i = l.begin(); i != l.end(); i++) {
		if (*i > max)
			max = *i;
		if (*i < min)
			min = *i;
	}
	type sum = max + min;
	for (auto i = l.begin(); i != l.end(); i++) {
		*i = *i + sum;
	}
}
