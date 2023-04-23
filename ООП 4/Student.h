#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

//Класс Student наследуется от класса Person
class Student :
    public Person
{
protected:
    //Поля "предмет" и "оценка"
    string subject; 
    int mark;
public:
    //Конструктооры и деструктор
    Student();
    Student(string, int, string, int);
    Student(const Student&);
    ~Student();
    //Геттер и сеттер для поля subject
    string get_subject();
    void set_subject(string);
    //Геттер и сеттер для поля mark
    int get_mark();
    void set_mark(int);
    //Метод для проверки оценок
    void ChekMark();
    //Перегрузка оператора присваивания
    Student& operator=(const Student&);
    //Глобальные операторы функции для ввода/вывода
    friend istream& operator>>(istream& in, Student&);
    friend ostream& operator<<(ostream& out, const Student&);
};

