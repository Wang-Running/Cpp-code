#define _CRT_SECURE_NO_WARNINGS

//引用
//不是新定义一个变量，而是给已存在变量取了一个别名，编译器不会为引用变量开辟内存空间，它和它
//引用的变量共用同一块内存空间
//特性：引用在定义时必须初始化
// 一个变量可以有多个引用
//引用一旦引用一个实体，再不能引用其他实体

#include <iostream>
using namespace std;

// 一个变量可以有多个引用
void TestRef()
{
	int a = 10;
	int& b = a;//<====定义引用类型
	int& c = b;
	int& d = c;
}

//常引用
//权限缩放问题
void TestConstRef()
{
	const int a = 10;
	//int& ra = a; // 该语句编译时会出错，a为常量
	const int& ra = a;
	// int& b = 10; // 该语句编译时会出错，b为常量
	const int& b = 10;
	double d = 12.34;
	//int& rd = d; // 该语句编译时会出错，类型不同
	const int& rd = d;
}


#define Add(x,y) x+y