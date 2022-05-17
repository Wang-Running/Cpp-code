#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using namespace std;

//struct ListNode
//{
//	int F(int x)
//	{
//		return x;
//	}
//	int val;
//	struct ListNode* next;
//};

//int main()
//{
//	return 0;
//}
//#include <cassert>
//#include <iostream>
//using namespace std;
//
//class Food
//{
//public:
//	成员函数
//	void Init(const char* name, int num)
//	{
//		strcpy(_name, name);
//		_num = num;
//	}
//	void Print()
//	{
//		cout << _name << " " << _num << endl;
//	}
//private:
//	成员变量
//	char _name[10];
//	int _num;
//};
//
//int main()
//{
//	Food egg;
//	egg.Init("鸡蛋",2);
//	egg.Print();
//	
//	return 0;
//}

//封装
//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//};
//
//void StackInit(struct Stack* ps)
//{
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//int StackTop(struct Stack* ps)
//{
//	assert(ps);
//	assert(ps->top>0);
//	return ps->a[ps->top - 1];
//}


// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1(){}
private:
	int _a;
};

// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};
// 类中什么都没有---空类
class A3
{};


#include "stack.h"

//int main()
//{
//	Stack ST;
//	ST.Init();
//	//cout << ST._top << endl;
//
//	Stack ST1;
//	ST1.Init();
//	//cout<<ST1._top<<endl;
//
//	//规范操作
//	//int top = ST.Top();
//
//	//不规范操作
//	//int top1 = ST._a[ST._top]; //越界
//	//int top2 = ST._a[ST._top-1];//正常
//
//	A1 a;
//	A2 aa;
//	A3 aaa;
//	cout << sizeof(a) << endl;
//	cout << sizeof(aa) << endl;
//	cout << sizeof(aaa) << endl;
//	return 0;
//}

//日期类
//class Date
//{
//public:
//	void Time(int year, int month, int day)
//	{
//		this = nullptr;
//
//
//
//
//
//		this->_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//void Print()
//	//{
//	//	cout << _year << "-" << _month << "-" << _day << endl;
//	//}
//
//	void Print()
//	{
//		cout << this << endl;
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//
//int main()
//{
//	Date d1, d2;
//	d1.Time(2001, 5, 15);
//	d2.Time(2022, 10, 30);
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//	d1.Print();
//	d2.Print();
//
//	//d1.Print(&d1);
//	//d2.Print(&d2);
//
//	return 0;
//}

////this指针第一题
//class A
//{
//public:
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Show();
//}


//this指针第二题
//class A
//{
//public:
//	void Show()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Show();
//}
//


struct A{

	long a1;

	short a2;

	int a3;

	int *a4;

};

int main()
{
	cout << sizeof(A) << endl;
	return 0;
}