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
	int a = 10;
	int& b = a;//<====������������
	int& c = b;
	int& d = c;
}

//������
//Ȩ����������
void TestConstRef()
{
	const int a = 10;
	//int& ra = a; // ��������ʱ�����aΪ����
	const int& ra = a;
	// int& b = 10; // ��������ʱ�����bΪ����
	const int& b = 10;
	double d = 12.34;
	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
	const int& rd = d;
}


#define Add(x,y) x+y