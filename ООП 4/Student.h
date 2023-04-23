#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

//����� Student ����������� �� ������ Person
class Student :
    public Person
{
protected:
    //���� "�������" � "������"
    string subject; 
    int mark;
public:
    //������������� � ����������
    Student();
    Student(string, int, string, int);
    Student(const Student&);
    ~Student();
    //������ � ������ ��� ���� subject
    string get_subject();
    void set_subject(string);
    //������ � ������ ��� ���� mark
    int get_mark();
    void set_mark(int);
    //����� ��� �������� ������
    void ChekMark();
    //���������� ��������� ������������
    Student& operator=(const Student&);
    //���������� ��������� ������� ��� �����/������
    friend istream& operator>>(istream& in, Student&);
    friend ostream& operator<<(ostream& out, const Student&);
};

