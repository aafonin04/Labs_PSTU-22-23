#include <iostream>
#include <string>
#include <Windows.h>
#include "Student.h"
#include "Person.h"
using namespace std;

//Функция принимает объект базового класса как параметр
void f1(Person& P) {
	P.set_name("Андрей");
}
//Функция возвращает объект производного класса как результат
Person f2() {
	Person first("Иван", 18);
	return first;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Работа с классом Person
	Person a;
	cout << "Первый экземпляр:" << endl;
	cin >> a;
	cout << "---------------" << endl;
	cout << a;
	Person b("Сергей", 19);
	cout << endl << "Второй экземпляр:" << endl;
	cout << b;
	a = b;
	cout << "---------------" << endl;
	cout << "Первый экземпляр изменён:" << endl;
	cout << a << endl;
	//Работа с классом Student
	Student c;
	cout << "Третий экземпляр:" << endl;
	cin >> c;
	cout << "---------------" << endl;
	cout << c;
	c.ChekMark();
	cout << endl;
	//Работа внешних функций
	f1(c);
	cout << "Изменено поле базового класса для третьего экземпляра:" << endl;
	cout << c << endl;
	a = f2();
	cout << "Первый экземпляр снова изменён:" << endl;
	cout << a << endl;
	return 0;
}