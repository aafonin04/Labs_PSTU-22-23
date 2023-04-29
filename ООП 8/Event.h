#pragma once

const int evNothing = 0; //Пустое событие
const int evMessage = 100; //Непустое событие
const int cmAdd = 1; //Добавить объект в группу
const int cmDel = 2; //Удалить объект из группы
const int cmGet = 3; //Вывести атрибут всех объектов
const int cmShow = 4; //Вывести всю группу
const int cmMake = 6; //Создать группу
const int cmQuit = 101; //Выход

//Класс событие
struct TEvent
{
	int what; //Тип события
	union
	{
		int command; //Код команды
		struct
		{
			int message;
			int a; //Параметр команды
		};
	};
};
