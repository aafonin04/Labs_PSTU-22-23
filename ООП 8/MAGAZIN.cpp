#include "MAGAZIN.h"
#include <iostream>
using namespace std;

MAGAZIN::MAGAZIN() :PRINT()
{
	pages = 0;
}
MAGAZIN::MAGAZIN(string s1, string s2, int p) :PRINT(s1, s2)
{
	pages = p;
}
MAGAZIN::MAGAZIN(const MAGAZIN& M)
{
	name = M.name;
	author = M.author;
	pages = M.pages;
}
MAGAZIN::~MAGAZIN() {}
void MAGAZIN::Show()
{
	cout << "Название: " << name << endl;
	cout << "Автор: " << author << endl;
	cout << "Количество страниц: " << pages << endl;
}
void MAGAZIN::Input()
{
	cout << "Название? "; cin >> name;
	cout << "Автор? "; cin >> author;
	cout << "Количество страниц? "; cin >> pages;
}
int MAGAZIN::get_pages() {
	return pages;
}
void MAGAZIN::set_pages(int p)
{
	pages = p;
}
MAGAZIN& MAGAZIN::operator=(const MAGAZIN& M)
{
	if (&M == this)
		return *this;
	name = M.name;
	author = M.author;
	pages = M.pages;
	return *this;
}
