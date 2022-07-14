#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include"string.h"

void test_string1()
{
	bit::mystring s1("hello word");
	cout << s1.c_str() << endl;
	s1[0] = 'x';
	cout << s1.c_str() << endl;
	for (size_t i = 0;i<s1.size();i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
}

void test_string2()
{
	bit::mystring s1("hello word");
	cout << s1.c_str() << endl;
	bit::mystring s2(s1);
	cout << s2.c_str() << endl;
}

//��ֵҲ�����ǳ��������
//��Ҫ���ظ�ֵ�����
void test_string3()
{
	bit::mystring s1("hello word");
	bit::mystring s2(s1);
	bit::mystring s3("1234865");
	s1 = s3;
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;
}

void test_string4()
{
	bit::mystring s1("hello word");
	cout << s1.c_str() << endl;

	//��Ҫ֧���޲ε�Ĭ�Ϲ���/ȫȱʡ
	bit::mystring s2;
	cout << s2.c_str() << endl;
}

//����
void test_string5()
{
	bit::mystring s1("hello word");
	cout << s1.c_str() << endl;
	s1.push_back('x');
	s1 += 'd';
	s1 += 'e';
	s1 += 'f';
	s1 += "nisn kas";
	s1.resize(14,'x');
	cout << s1.c_str() << endl;
	
}

int main()
{
	try
	{
		test_string5();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}