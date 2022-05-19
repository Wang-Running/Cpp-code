#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
using namespace std;

//������ʾ�����������ɵ�����Ĭ�Ϻ���

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
	//��������->ǳ����
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

	//1.Ĭ�����ɹ��캯��

	//2.�޲������캯��
	//Date()
	//{
	//	_year = 2022;
	//	_month = 5;
	//	_day = 15;
	//}
	//3.���εĹ��캯��
	Date(int year=2000,int month=1,int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void func(Date d)
	{

	}
	//�������캯��
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

//�����������������:������Ƚϣ���ô���������β�
//����ֵ���������Ľṹ���Ƚ���ȷ�����ټ��ɣ���bool
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

	//�������к���

	//if (d1.operator==(d2))
	//{
	//	cout << "==" << endl;
	//}

	if (d1 == d2)  //���������Զ�����Ϊ d1.operator==(d2)
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