#include <iostream>
#include <map>
#include "Pair.h"
#include <algorithm>
#include <vector>
using namespace std;

typedef multimap<int, Pair> tmap;
Pair f, s;

struct mean {
    void operator()(pair<int, Pair> p) {
        ++n;
        s_f += p.second.get_first();
        s_s += p.second.get_second();
    }

    Pair get_result() { return Pair(s_f / n, s_s / n); }

private:
    int n{ 0 };
    int s_f{ 0 };
    double s_s{ 0 };
};

struct del {
    void operator()(pair<int, Pair> p) {
        if (f < p.second && p.second < s) {
            to_del.push_back(p.first);
            ++n;
        }
    }
    int n{ 0 };
    vector<int> to_del;
};

tmap make_map(int n) {
    tmap m;
    Pair p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        m.insert(make_pair(i, p));
    }
    return m;
}

void print_map(tmap m) {
    for (auto i : m) {
        cout << i.first << ':' << i.second << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Количество элементов? ";
    cin >> n;
    tmap m = make_map(n);
    print_map(m);
    cout << "Список после добавления среднего арифметического" << endl;
    cout << "На какую позицию нужно вставить элемент? ";
    cin >> n;
    mean mn = for_each(m.begin(), m.end(), mean());
    Pair res = mn.get_result();
    m.insert(make_pair(n, res));
    print_map(m);
    cout << "Удаление элементов из диапазона" << endl;
    cin >> f;
    cin >> s;
    del d = for_each(m.begin(), m.end(), del());
    print_map(m);
    mn = for_each(m.begin(), m.end(), mean());
    res = mn.get_result();
    for_each(m.begin(), m.end(), [res](pair<const int, Pair>& p) { p.second = p.second - res; });
    cout << endl << "Добавление суммы минимального и максимального элементов" ;
    print_map(m);
    return 0;
}