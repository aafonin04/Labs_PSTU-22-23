#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error //Базовый класс
{
public:
	virtual void what() {};
};
class SizeError :public Error //Ошибка в размере списка
{
protected:
	string msg;
public:
	SizeError() { msg = "Size error\n"; }
	virtual void what() { cout << msg; }
};
class MaxSizeError :public SizeError //Превышение максимального размера
{
protected:
	string msg_;
public:
	MaxSizeError() { SizeError(); msg_ = "Size > MAXSIZE\n"; }
	virtual void what() { cout << msg << msg_; }
};
class EmptySizeError :public SizeError //Удаление из пустого списка
{
protected:
	string msg_;
public:
	EmptySizeError() { SizeError(); msg_ = "List is empty\n"; }
	virtual void what() { cout << msg << msg_; }
};
class DiffSizeError :public SizeError //Удаление из пустого списка
{
protected:
	string msg_;
public:
	DiffSizeError() { SizeError(); msg_ = "Different sizes of lists\n"; }
	virtual void what() { cout << msg << msg_; }
};
class IndexError :public Error //Ошибка в индексе списка
{
protected:
	string msg;
public:
	IndexError() { msg = "Index error\n"; }
	virtual void what() { cout << msg; }
};
class IndexError1 :public IndexError //Индекс меньше нуля
{
protected:
	string msg_;
public:
	IndexError1() { IndexError(); msg_ = "Index < 0\n"; }
	virtual void what() { cout << msg << msg_; }
};
class IndexError2 :public IndexError //Индекс больше текущего размера списка
{
protected:
	string msg_;
public:
	IndexError2() { IndexError(); msg_ = "Index > size\n"; }
	virtual void what() { cout << msg << msg_; }
};