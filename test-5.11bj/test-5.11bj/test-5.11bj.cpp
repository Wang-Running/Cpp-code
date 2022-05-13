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

int main()
{
	Food egg;
	egg.Init("鸡蛋",2);
	egg.Print();
	
	return 0;
}