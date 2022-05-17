#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//日期类示例空类下生成的六个默认函数

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

	//1.默认生成构造函数

	//2.无参数构造函数
	Date()
	{
		_year = 2022;
		_month = 5;
		_day = 15;
	}
	//3.带参的构造函数
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