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
#include <cassert>
#include <iostream>
using namespace std;

class Food
{
public:
	//成员函数
	void Init(const char* name, int num)
	{
		strcpy(_name, name);
		_num = num;
	}
	void Print()
	{
		cout << _name << " " << _num << endl;
	}
private:
	//成员变量
	char _name[10];
	int _num;
};

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

class Stack
{
public:
	void StackInit(struct Stack* ps)
	{
		ps->_a = NULL;
		ps->_top = 0;
		ps->_capacity = 0;
	}

	int StackTop(struct Stack* ps)
	{
		assert(ps);
		assert(ps->_top>0);
		return ps->_a[ps->_top - 1];
	}
private:
	int* _a;
	int _top;
	int _capacity;
};



int main()
{
	Stack ST;
	ST.StackInit(&ST);

	//规范操作
	int top = ST.StackTop(&ST);

	//不规范操作
	int top1 = ST._a[ST._top]; //越界
	int top2 = ST._a[ST._top-1];//正常
	return 0;
}