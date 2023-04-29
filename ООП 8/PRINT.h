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
    PRINT(); //����������� ��� ����������
    PRINT(string, string); //����������� � �����������
    PRINT(const PRINT&); ;//����������� �����������
    virtual ~PRINT(); ;//����������
    void Show();
    void Input();
    //�������
    string get_name();
    string get_author();
    //������� 
    void set_name(string);
    void set_author(string);
    PRINT& operator=(const PRINT&); //���������� �������� ������������
    void HandleEvent(const TEvent& e);
};
