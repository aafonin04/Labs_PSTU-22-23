#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc); //������� ��� ������
	if (!stream)
		return -1; //������ �������� �����
	int n;
	Pair p;
	cout << "���������� �����������? "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p; //���� ��������� ������� �� ������������ ������
		stream << p << "\n"; //������ ������� � �������� �����
	}
	stream.close(); //������� �����
	return n; //������� ���������� ���������� ��������
}
int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in); //������� ��� ������
	if (!stream)
		return -1; //������ �������� �����
	Pair temp; 
	int i = 0;
	while (stream >> temp)
	{
		cout << temp << "\n";
		i++;
	}
	stream.close();
	return i;
}
int file_deleteRecordsUnderValue(const char* filename, int intlimitValue, double doublelimitValue) {
	fstream fromStream(filename, ios::in);
	fstream inStream("tmpFile", ios::out | ios::trunc);
	int i = 0;
	Pair p;
	while (fromStream >> p) {
		if (p.get_a() >= intlimitValue && p.get_b() >= doublelimitValue && !fromStream.eof()) {
			inStream << p;
			i++;
		}
	}
	fromStream.close();
	inStream.close();
	remove(filename);
	rename("tmpFile", filename);
	return i;
}
int file_addRecordsWithValue(const char* filename, int intcurrentValue, double doublecurrentValue, int intadditionalValue, double doubleadditionalValue) 
{
	fstream fromStream(filename, ios::in);
	fstream inStream("tmpFile", ios::out | ios::trunc);
	int i = 0;
	Pair p;
	while (fromStream >> p) {
		if ((p.get_a() == intcurrentValue && p.get_b() == doublecurrentValue) && !fromStream.eof()) {
			p = p + intadditionalValue;
			p = p + doubleadditionalValue;
			i++;
		}
		inStream << p;
	}
	fromStream.close();
	inStream.close();
	remove(filename);
	rename("tmpFile", filename);
	return i;
}
int add_file(const char* f_name, int k, Pair pp)
{
	fstream temp("temp", ios::out); //������� ��� ������
	fstream stream(f_name, ios::in); //������� ��� ������
	if (!stream)
		return -1; //������ �������� �����
	Pair p; 
	int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		i++;
		temp << p;
		if (i == k)
		{
			temp << pp; //�������� � temp ����� ������
			l++;
		}
	}
	stream.close(); 
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l; //���������� �����������
}
