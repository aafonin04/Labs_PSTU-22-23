#pragma once
#include<iostream>
#include <string>
#include "Object.h"
using namespace std;

class PRINT :
    public Object
{
protected:
    string name;
    string author;
public:
    PRINT(); //Конструктор без параметров
    PRINT(string, string); //Конструктор с параметрами
    PRINT(const PRINT&); ;//Конструктор копирования
    virtual ~PRINT(); ;//Деструктор
    void Show();
    void Input();
    //Геттеры
    string get_name();
    string get_author();
    //Сеттеры 
    void set_name(string);
    void set_author(string);
    PRINT& operator=(const PRINT&); //Перегрузка операции присваивания
    void HandleEvent(const TEvent& e);
};
