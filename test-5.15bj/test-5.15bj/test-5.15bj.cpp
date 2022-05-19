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
	//拷贝构造->浅拷贝
	Stack(const Stack& ST)
	{
		_a = ST._a;
		_top = ST._top;
		_capacity = ST._capacity;
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

	void func(Date d)
	{

	}
	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
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
	//
	bool operator==(const Date& d2)
	{
		return _year == d2._year&&
			_month == d2._month&&
			_day == d2._day;
	}
private:
	int _year;
	int _month;
	int _day;
	A aa;
};

//参数：看运算符来定:两个相比较，那么就有两个形参
//返回值：看运算后的结构，比较相等返回真假即可，即bool
//bool operator==(Date d1, Date d2)
//{
//	return d1._year == d2._year&&
//		d1._month == d2._month&&
//		d1._day == d2._day;
//}

int main()
{
	Date d1;
	Date d2;

	//调用类中函数

	//if (d1.operator==(d2))
	//{
	//	cout << "==" << endl;
	//}

	if (d1 == d2)  //编译器会自动处理为 d1.operator==(d2)
	{
		cout << "==" << endl;
	}

	//func(d1);
	//Stack ST1(1);
	//Stack ST2(ST1);
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