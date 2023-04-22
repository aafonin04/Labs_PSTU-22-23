#include <iostream>
#include "Progress.h"
using namespace std;

void Progress::Init(double F, int S) { //Реализация метода для инициализации полей класса
	first = F;
	second = S;
}

void Progress::Read() { //Реализация метода для чтения значений полей класса
	cout << "Первый элемент прогрессии: "; cin >> first;
	cout << "Постоянное отношение прогрессии: "; cin >> second;
}

void Progress::Show() { //Реализация метода для вывода значений полей класса
	cout << "Первый элемент прогресси: " << first << endl;
	cout << "Постоянное отношение прогрессии: " << second << endl;
}

double Progress::Element(int j) { //Реализация метода нахождения j-го элемента
	return first * pow(second, j-1);
}
