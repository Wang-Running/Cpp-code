#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//������ʾ�����������ɵ�����Ĭ�Ϻ���

class Stack
{
public:

private:
	int* _a;
	int _top;
	int _capacity;
};

class Date
{
public:
	//void DateInit(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	//1.Ĭ�����ɹ��캯��

	//2.�޲������캯��
	Date()
	{
		_year = 2022;
		_month = 5;
		_day = 15;
	}
	//3.���εĹ��캯��
	Date(int year=2000,int month=1,int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018,1);
	Date d2;
	return 0;
}