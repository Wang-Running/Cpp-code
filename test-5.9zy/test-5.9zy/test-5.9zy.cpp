#define _CRT_SECURE_NO_WARNINGS

//����
//�����¶���һ�����������Ǹ��Ѵ��ڱ���ȡ��һ������������������Ϊ���ñ��������ڴ�ռ䣬������
//���õı�������ͬһ���ڴ�ռ�
//���ԣ������ڶ���ʱ�����ʼ��
// һ�����������ж������
//����һ������һ��ʵ�壬�ٲ�����������ʵ��
//
//#include <iostream>
//using namespace std;


// һ�����������ж������
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
//	//�ٴζ���һ������
//	int f = 5;
//	//�����bָ��f ����
//	b = f;
//}




//������
//Ȩ����������
//void TestConstRef()
//{
//	const int a = 10;
//
//	// Ȩ�޷Ŵ�aΪ�������������ñ���
//	/*int& ra = a; */
//
//	//Ȩ����ȵĲ���
//	//const int& ra = a;
//
//	//Ȩ����С
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
//	�ٴε��ã�ͬ���ĵ�ַ����ͬ������
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


//�ͺ������ ,�ֺ�����
//#define ADD(int x,int y) return x+y;

//#define ADD(x,y) return x+y;

//#define ADD(x,y) (x+y);

//�������ţ���������ȼ�����
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
//	auto int a = 10;  //�ȼ���int a = 10;
//	                  //auto���Ժ���
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
//	//�Ƴ�cΪָ��
//	auto c = &b;
//
//	//Ҳ����ָ������һ��ָ������
//	auto* d = &b;
//
//	//ָ������һ������
//	auto& e = b;
//
//
//	//�������
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

//// ����ʧ��
//void Test(auto a)
//{}
//
////auto������Ϊ�β����ͣ���Ϊ�������޷���a��ʵ�����ͽ����Ƶ�
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
//	//c������
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
//	//c++�У���Χforѭ��
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