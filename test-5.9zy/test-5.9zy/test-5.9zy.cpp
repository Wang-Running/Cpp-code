#define _CRT_SECURE_NO_WARNINGS

//����
//�����¶���һ�����������Ǹ��Ѵ��ڱ���ȡ��һ������������������Ϊ���ñ��������ڴ�ռ䣬������
//���õı�������ͬһ���ڴ�ռ�
//���ԣ������ڶ���ʱ�����ʼ��
// һ�����������ж������
//����һ������һ��ʵ�壬�ٲ�����������ʵ��

#include <iostream>
using namespace std;


// һ�����������ж������
void TestRef()
{

	//int& a;

	int a = 10;
	int& b = a;
	int& c = b;
	int& d = c;

	//�ٴζ���һ������
	int f = 5;
	//�����bָ��f ����
	b = f;
}




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