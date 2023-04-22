#pragma once
class Progress 
{
private:
	double first; //Первый элемент прогрессии a0
	int second; //Постоянное отношение r
public:
	void Init(double, int); //Метод для инициализации полей
	void Read(); //Метод для чтения значений полей
	void Show(); //Метод для вывода значений полей
	double Element(int); //Вычисление j-го элемента
};

