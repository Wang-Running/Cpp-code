#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
//声明一个函数
//inline int f(int x);

//直接定义
inline int f(int x)
{
	x = 5;
	cout << x << endl;
}