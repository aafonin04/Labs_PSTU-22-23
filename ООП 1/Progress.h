#pragma once
class Progress 
{
private:
	double first; //������ ������� ���������� a0
	int second; //���������� ��������� r
public:
	void Init(double, int); //����� ��� ������������� �����
	void Read(); //����� ��� ������ �������� �����
	void Show(); //����� ��� ������ �������� �����
	double Element(int); //���������� j-�� ��������
};

