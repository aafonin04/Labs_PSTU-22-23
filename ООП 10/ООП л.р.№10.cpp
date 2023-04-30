#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_work.h"
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Pair p;
	int k, c;
	char file_name[30];
	do
	{ //Меню
		cout << "1.Создать файл"; 
		cout << "\n2.Вывести содержимое файла"; 
		cout << "\n3.Удалить записи из файла меньше заданного значения";
		cout << "\n4.Увеличить все записи с заданным значением на число L";
		cout << "\n5.Добавить K записей после элемента с заданным номером";
		cout << "\n0.Выход\n";
		cout << "Ваш выбор: "; cin >> c;
		switch (c)
		{
		case 1: cout << "Название файла? "; cin >> file_name; //Задаем имя файла
			k = make_file(file_name); //Вызов функции для записи в файл
			if (k < 0)
				cout << "Не удалось создать файл"; //Вывод сообщения об ошибке
			break;
		case 2: cout << "Название файла? "; cin >> file_name; //Задаем имя файла
			k = print_file(file_name); //Вызов функции для печати файла
			if (k == 0)
				cout << "Файл пустой\n"; //Если файл пустой
			if (k < 0)
				cout << "Не удалось открыть файл\n"; //Если файл нельзя открыть
			break;
		case 3: cout << "Название файла? "; cin >> file_name;
			int intlimitValue;
			double doublelimitValue;
			cout << "Целое значение? "; cin >> intlimitValue;
			cout << "Дробное значение? "; cin >> doublelimitValue;
			k = file_deleteRecordsUnderValue(file_name, intlimitValue, doublelimitValue);
			if (k == 0)
				cout << "Файл пустой\n";
			if (k < 0)
				cout << "Не удалось открыть файл\n";
			break;
		case 4: cout << "Название файла? "; cin >> file_name;
			int L1;
			double L2;
			cout << "Целое значение? "; cin >> intlimitValue;
			cout << "Дробное значение? "; cin >> doublelimitValue;
			cout << "Число L для целого типа? "; cin >> L1;
			cout << "Число L для дробного типа? "; cin >> L2;
			k = file_addRecordsWithValue(file_name, intlimitValue, doublelimitValue, L1, L2);
			if (k == 0)
				cout << "Файл пустой\n";
			if (k < 0)
				cout << "Не удалось открыть файл\n";
			break;
		case 5: cout << "Название файла? "; cin >> file_name;
			int n, count;
			Pair p1;
			cout << "№ элемента, после котрого нужно вставить новые элементы? "; cin >> n;
			cout << "Сколько элементов нужно добавить? "; cin >> count;
			cout << "Новая пара чисел:" << endl;
			cin >> p1;
			k = add_file(file_name, n, p1);
			if (k > 0) {
				for (int i = 1; i < count; i++) {
					cout << "Новая пара чисел:" << endl;
					cin >> p1;
					k = add_file(file_name, n + 1, p1);
					n++;
				}
			}
			if (k == 0) 
				cout << "Файл пустой\n";
			if (k < 0) 
				cout << "Не удалось открыть файл\n";
			break;
		}
	} while (c != 0);
	return 0;
}