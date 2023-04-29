#include "Object.h"
#include "PRINT.h"
#include "Event.h"
#include <iostream>
using namespace std;

PRINT::PRINT()
{
	name = "";
	author = "";
}
PRINT::PRINT(string s1, string s2)
{
	name = s1;
	author = s2;
}
PRINT::PRINT(const PRINT& P)
{
	name = P.name;
	author = P.author;
}
PRINT::~PRINT() {}
void PRINT::Show()
{
	cout << "��������: " << name << endl;
	cout << "�����: " << author << endl;
}
void PRINT::Input()
{
	cout << "��������? "; cin >> name;
	cout << "�����? "; cin >> author;
}
string PRINT::get_name()
{
	return name;
}
string PRINT::get_author()
{
	return author;
}
void PRINT::set_name(string s)
{
	name = s;
}
void PRINT::set_author(string s)
{
	author = s;
}
PRINT& PRINT::operator=(const PRINT& P)
{
	if (&P == this)
		return *this;
	name = P.name;
	author = P.author;
	return *this;
}
void PRINT::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage) //�������-���������
	{
		switch (e.command)
		{
		case cmGet:cout << "��������: " << get_name() << endl;
			break;
		}
	}
}