#include "Dialog.h"
#include "Event.h"
#include "Vector.h"
#include <iostream>
using namespace std;

//Конструктор
Dialog::Dialog() :Vector()
{
	EndState = 0;
}
//Деструктор
Dialog::~Dialog() {}
//Получение события
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "m+-szq"; //Строка содержит коды операций
	string s;
	string param;
	char code;
	cout << "Введите выбранную команду > ";
	cin >> s; code = s[0]; //Первый символ команды
	if (OpInt.find(code) >= 0) { //Является ли символ кодом операции
		event.what = evMessage;
		switch (code) {
		case 'm':event.command = cmMake; break; //Создать группу
		case '+': event.command = cmAdd; break; //Добавить объект в группу
		case '-': event.command = cmDel; break; //Удалить объект из группы
		case 's': event.command = cmShow; break; //Просмотр группы
		case 'z': event.command = cmGet; break; //Наазвания элементов группы
		case'q': event.command = cmQuit; break; //Конец работы
		}
		//Выделяем параметры команды, если они есть
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str()); //Преобразуем парметр в число
			event.a = A; //Записываем в сообщение
		}
	}
	else event.what = evNothing; //Пустое событие
}
int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event); //Получить событие
		HandleEvent(event); //Обработать событие
	} while (!Valid());
	return EndState;
}
bool Dialog::Valid()
{
	if (EndState == 0)
		return 0;
	else
		return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing; //Пустое событие
}
void Dialog::EndExec()
{
	EndState = 1;
}
//обработчик событий
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake: //Создание группы
			size = event.a; //Размер группы
			beg = new Object * [size]; //Выделяем память под массив указателей
			cur = 0; //Текущая позиция
			ClearEvent(event); //Очищаем событие
			break;
		case cmAdd: //Добавление
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del(); //Удаление
			ClearEvent(event);
			break;
		case cmShow:Show(); //Просмотр
			ClearEvent(event);
			break;
		case cmQuit:EndExec(); //Выход
			ClearEvent(event);
			break;
		default: Vector::HandleEvent(event);
		}
	}
}
