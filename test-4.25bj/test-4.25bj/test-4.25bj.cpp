#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include "List.h"
//#include "Queue.h"
//using namespace A::data;
//int main()
//{
//	struct Node n1;
//	a = 3;
//	b = 4;
//	struct cache ::Node n3;
//	printf("%d %d",a,b);
//	return 0;
//}



//命名冲突
//#include <stdio.h>
//#include <stdlib.h>
//
////定义全局变量
//namespace A
//{
//	int rand = 0;
//}
//
//int main()
//{
//	printf("%d ",rand);
//	return 0;
//}

//#include <stdio.h>
//
////定义全局变量
//int rand = 0;
//
//namespace A
//{
//	int rand = 2;
//}
//
//int main()
//{
//	int rand = 1;
//	printf("%d ",A::rand);
//	return 0;
//}





//namespace anm  //命名空间域
//{
//	int rand = 0;
//}
//
//int a = 0;

//int main()
//{
//	int a = 1;
//
//	//::域作用限定符
//
//	printf("%d\n",anm::rand);
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//	return 0;
//}

//using namespace A;
//int main()
//{
//	struct data::Node n1;
//	struct data::Node n2;
//	struct data::Node n3;
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//namespace C
//{
//	int f = 0;
//	int rand = 1;
//	namespace D
//	{
//		int d = 4;
//		namespace E
//		{
//			int e = 5;
//			char g = 'p';
//		}
//	}
//}
//
////释放E中所有内容
//using namespace C::D::E;
//int main()
//{
//	e += 1;
//	printf("%d\n",e);
//	printf("%d\n", rand);
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "hello word" << endl;
//	int a = 0;
//	cin >> a;
//	cout << a<<endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;//std 封C++库的命名空间

//全放不安全，不放太麻烦
//放一些常用的
//using std::cout;


//int cout = 0;

//int main()
//{
//	/*cout << "hello word" << endl;*/
//	cout << "hello word" << std::endl;
//	cout << "hello word" << std::endl;
//
//	//std::cout << cout << std::endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;

//全缺省参数
//void TestA(int a = 5, int b = 10, int c = 15)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl<<endl;
//}

//半缺省参数（缺省部分参数）
//void TestA(int a , int b = 10, int c = 15)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	TestA(1);
//	TestA(1,5);
//	TestA(1,5,6);
//	return 0;
//}

//函数重载
//是函数的一种特殊情况，C++允许在同一作用域中声明几个功能类似的同名函数，这些同名函数的
//形参列表(参数个数 或 类型 或 顺序)必须不同，常用来处理实现功能类似数据类型不同的问题

#include <iostream>
using namespace std;

//void Swap(int* a,int* b)
//{
//	int tmp = *b;
//	*b = *a;
//	*a = tmp;
//}
//
//void Swap(double* a, double* b)
//{
//	double tmp = *b;
//	*b = *a;
//	*a = tmp;
//}


int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}


int main()
{
	cout << Add(1,2) << endl;
	cout << Add(1.3, 2.4) << endl;
	return 0;
}

//#include <stdio.h>
//
//int Add(int left, int right)
//{
//	return left + right;
//}

//double Add(double left, double right)
//{
//	return left + right;
//}


//int main()
//{
//	Add(1,2);
//	return 0;
//}