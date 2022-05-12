#define _CRT_SECURE_NO_WARNINGS

//引用
//不是新定义一个变量，而是给已存在变量取了一个别名，编译器不会为引用变量开辟内存空间，它和它
//引用的变量共用同一块内存空间
//特性：引用在定义时必须初始化
// 一个变量可以有多个引用
//引用一旦引用一个实体，再不能引用其他实体
//
//#include <iostream>
//using namespace std;


// 一个变量可以有多个引用
//void TestRef()
//{
//
//	//int& a;
//
//	int a = 10;
//	int& b = a;
//	int& c = b;
//	int& d = c;
//
//	//再次定义一个变量
//	int f = 5;
//	//令别名b指向f ？？
//	b = f;
//}




//常引用
//权限缩放问题
//void TestConstRef()
//{
//	const int a = 10;
//
//	// 权限放大，a为常量，不能引用别名
//	/*int& ra = a; */
//
//	//权限相等的操作
//	//const int& ra = a;
//
//	//权限缩小
//	int c = 5;
//	const int& d = c;
//	const int& f = d;
//}


//void TestConstRef()
//{
//	const int& a = 10;
//
//	double b = 2.2;
//	const int& c = b;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}

//int main()
//{
//	int a = 5, b = 3;
//	Swap(a,b);
//	double c = 2.3, d = 5.5;
//	Swap(c,d);
//	return 0;
//}

//int& Count()
//{
//	static int n = 5;
//	n++;
//	cout << &n << endl;
//	return n;
//}

//int main()
//{
//	int& ret = Count();
//	cout << ret << endl;
//	cout << &ret << endl;
//	再次调用，同样的地址，不同的数据
//	cout << ret << endl;
//	cout << &ret << endl;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//
//	int& ra = a;
//	ra = 20;
//
//	int* pa = &a;
//	*pa = 20;
//
//	return 0;
//}


//和函数搞混 ,分号滥用
//#define ADD(int x,int y) return x+y;

//#define ADD(x,y) return x+y;

//#define ADD(x,y) (x+y);

//不带括号，会出现优先级问题
//#define ADD(x,y) x+y

//#define ADD(x,y) ((x)+(y))

//#include "test.h"
//
//inline int ADD(int x,int y)
//{
//	int sum = x + y;
//	//sum++;
//	//sum++;
//	//sum++;
//	//sum++;
//	//sum++;
//	//sum++;
//	//sum++;
//	//sum++;
//	//sum++;
//	return sum;
//}
//
//int main()
//{
//	ADD(1,2);
//	ADD(1, 3);
//	ADD(1, 4);
//	ADD(1, 5);
//	f(10);
//	//printf("%d ",ADD(1,2));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	auto int a = 10;  //等价于int a = 10;
//	                  //auto可以忽略
//	printf("%d \n",a);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int Test()
//{
//	return 6;
//}
//
//int main()
//{
//	auto a = 2;
//	double b = 3.8;
//
//	//推出c为指针
//	auto c = &b;
//
//	//也可以指定其是一个指针类型
//	auto* d = &b;
//
//	//指定其是一个引用
//	auto& e = b;
//
//
//	//输出类型
//	cout << typeid(a).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int Test()
//{
//	return 6;
//}
//
//int main()
//{
//	auto a = 2, b = 3.5;
//	return 0;
//}


#include <iostream>
using namespace std;

//// 编译失败
//void Test(auto a)
//{}
//
////auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
//
//void Test()
//{
//	int a[] = { 1, 2, 3 };
//	auto b[] = { 4,5,6 };
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//
//	//c语言中
//	for (int i = 0; i<sizeof(arr) / sizeof(int); i++)
//	{
//		arr[i] *= 2;;
//	}
//
//	for (int i = 0;i<sizeof(arr)/sizeof(int);i++)
//	{
//		printf("%d ",arr[i]);
//	}
//
//	printf("\n");
//
//	//c++中，范围for循环
//
//	for (auto& e : arr)
//	{
//		e /= 2;
//	}
//
//	for (auto e:arr)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	return 0;
//}

void f(int x)
{
	cout << 5 << endl;
}

void f(int* x)
{
	cout << 6 << endl;
}


int main()
{
	f(0);
	f(NULL);
	f(nullptr);
	return 0;
}