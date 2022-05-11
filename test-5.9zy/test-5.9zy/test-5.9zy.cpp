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

	//int& a;

	int a = 10;
	int& b = a;
	int& c = b;
	int& d = c;

	//再次定义一个变量
	int f = 5;
	//令别名b指向f ？？
	b = f;
}




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

int main()
{
	int a = 10;

	int& ra = a;
	ra = 20;

	int* pa = &a;
	*pa = 20;

	return 0;
}



//#define Add(x,y) x+y