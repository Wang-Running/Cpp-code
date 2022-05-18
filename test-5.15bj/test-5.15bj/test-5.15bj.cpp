#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
using namespace std;

//日期类示例空类下生成的六个默认函数

class A
{
public:
	A()
	{
		a = 5;
	}
	~A()
	{
		a = 0;
	}
private:
	int a;
};

class Stack
{
public:
	Stack(int capacity=10)
	{
		_a = (int*)malloc(sizeof(int)*capacity);
		assert(_a);
		_top = 0;
		_capacity = capacity;
	}
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
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
	//Date()
	//{
	//	_year = 2022;
	//	_month = 5;
	//	_day = 15;
	//}
	//3.带参的构造函数
	Date(int year=2000,int month=1,int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//Date(Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}
	~Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	A aa;
};

int main()
{
	Date d1;
	Date d2(d1);
	d1.Print();
	d2.Print();
	//Stack ST1(1);
	//Stack ST2(2);
	return 0;
}


//class MyQueue
//{
//public:
//	//
//private:
//	Stack ST1(1);
//	Stack ST2(2);
//};