#include <iostream>
#include <string>
#include <Windows.h>
#include "Salary.h"
using namespace std;

//Функция для возврата объекта как результата
Salary make_salary() {
	string n;
	double p;
	int b;
	cout << "Введите ФИО: "; getline(cin, n);
	cout << "Введите оклад: "; cin >> p;
	cout << "Введите премию: "; cin >> b;
	Salary H(n, p, b);
	return H;
}

//Функция для передачи объекта как параметра
void print_salary(Salary H) {
	H.show();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Конструктор без параметров
	cout << "Первый экземпляр" << endl;
	Salary H1;
	H1.show();
	cout << endl;
	//Конструктор с параметрами
	cout << "Второй экземпляр" << endl;
	Salary H2("Петров Сергей Викторович", 50000, 25000);
	H2.show();
	cout << endl;
	//Конструктор копирования
	cout << "Третий экземпляр" << endl;
	Salary H3 = H1;
	H3.show();
	cout << endl;
	//Применение модификаторов и селекторов для третьего экземпляра
	cout << "Изменённый третий экземпляр" << endl;
	H3.set_name("Иванов Андрей Петрович");
	H3.set_pay(40000);
	H3.set_bonus(20000);
	string n = H3.get_name();
	double p = H3.get_pay();
	int b = H3.get_bonus();
	cout << "ФИО: " << n << endl;
	cout << "Оклад: " << p << endl;
	cout << "Премия: " << b << endl;
	//Работа внешних функций
	cout << endl << "Четвертый экземпляр" << endl;
	Salary H4 = make_salary();
	cout << "-----------------" << endl;
	print_salary(H4);
	return 0;
}