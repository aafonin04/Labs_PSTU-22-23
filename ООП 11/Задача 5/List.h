#pragma once
#include <list>
#include <queue>
#include <iostream>
using namespace std;

template <typename type>
class List {
	priority_queue <type> pq;
	int size = pq.size();
public:
	List(int n);
	void print();
	~List() {};
	void mean();
	void add(type data) {
		pq.push(data);
	}
	void range(double, double);
	void minmax();
};

template <typename type>
priority_queue<type> copy_list_to_pq(list<type> l) {
	priority_queue<type> pq;
	for (auto it = l.begin(); it != l.end(); ++it) {
		pq.push(*it);
	}
	return pq;
}

template <typename type>
list<type> copy_pq_to_list(priority_queue<type> pq) {
	list<type> l;
	while (!pq.empty()) {
		l.push_back(pq.top());
		pq.pop();
	}
	return l;
}


template <typename type>
List<type>::List(int n) {
	type a; size = n;
	cout << "¬ведите значение\n";
	for (int i = 0; i < n; ++i) {
		cin >> a;
		this->add(a);
	}
}

template <typename type>
void List<type>::print() {
	list<type> l = copy_pq_to_list(pq);
	for (auto it = l.begin(); it != l.end(); ++it) {
		cout << *it << " ";
	}
}

template <typename type>
void List<type>::mean() {
	type s{};
	list<type> l = copy_pq_to_list(pq);
	for (auto it = l.begin(); it != l.end(); ++it) {
		s += *it;
	}
	s /= (double)size;
	cout << "—реднее значение " << s << endl;
	pq = copy_list_to_pq(l); this->add(s);

}

template <typename type>
void List<type>::range(double one, double two) {
	if (two < one) swap(one, two);
	list<type> l = copy_pq_to_list(pq);
	for (auto it = l.begin(); it != l.end();) {
		if (*it > one && two > *it) it = l.erase(it);
		else ++it;
	}
	pq = copy_list_to_pq(l);
}


template <typename type>
void List<type>::minmax() {
	list<type> l = copy_pq_to_list(pq);
	type mini = l.front(), maxi = l.front();
	for (auto it = l.begin(); it != l.end(); ++it) {
		if (*it < mini) mini = *it;
		if (*it > maxi) maxi = *it;
	}
	cout << "\nmin: " << mini;
	cout << "\nmax: " << maxi << endl;

	maxi += mini;
	for (auto it = l.begin(); it != l.end(); ++it) *it += maxi;
	pq = copy_list_to_pq(l);
}
