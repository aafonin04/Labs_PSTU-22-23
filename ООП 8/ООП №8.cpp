#include <iostream>
#include <Windows.h>
#include "PRINT.h"
#include "MAGAZIN.h"
#include "Vector.h"
#include "Dialog.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "m + число: создать группу" << endl;
	cout << "+: добавить элемент в группу" << endl;
	cout << "-: удалить элемент из группы" << endl;
	cout << "s: вывести информацию об элементах группы" << endl;
	cout << "z: вывести информацию о названиях всех элементов группы" << endl;
	cout << "q: конец работы " << endl << endl;
	Dialog D;
	D.Execute();
	return 0;
}