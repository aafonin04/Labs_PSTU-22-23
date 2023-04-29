#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog :
	public Vector
{
protected:
	int EndState;
public:
	Dialog(void); //Контруктор
	virtual ~Dialog(void); //Деструктор
	virtual void GetEvent(TEvent& event); //Получить событие
	virtual int Execute(); //Главный цикл обработки событий
	virtual void HandleEvent(TEvent& event); //Обработчик
	virtual void ClearEvent(TEvent& event); //Очистить событие
	bool Valid(); //Проверка атрибута EndState
	void EndExec(); //Обработка события «конец работы»
};

