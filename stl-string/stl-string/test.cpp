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


void test_string6()
{
	bit::mystring s1("hello word");
	//1.�±����
	for (size_t i = 0;i<s1.size();i++)
	{
		s1[i] += 1;
		cout << s1[i] << " ";
	}
	cout << endl;

	//2.����������
	bit::mystring::iterator it = s1.begin();
	while (it!=s1.end())
	{
		*it-=1;
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//3.��Χfor����--�ײ㱻�滻Ϊ������
	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;
}
//const����
void func(const bit::mystring& s)
{
	for (size_t i = 0; i<s.size(); i++)
	{
		//s[i] += 1;
		cout << s[i] << " ";
	}
	cout << endl;
	//2.����������
	bit::mystring::const_iterator it = s.begin();
	while (it != s.end())
	{
		//*it -= 1;
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//for (const char& e : s)
	for (auto& e : s)
	{
		//e += 1;
		cout << e << " ";
	}
	cout << endl;
}

//����
void test_string7()
{
	bit::mystring s("hello word");
	//s.insert(6, 'x');
	//cout << s.c_str() << endl;
	//s += '@';
	//cout << s.c_str() << endl;
	s.insert(1,"xxx");
	cout << s.c_str() << endl;
	s.earse(0, 3);
	cout << s.c_str() << endl;
	s.earse(5, 100);
	cout << s.c_str() << endl;
}

//���������
void test_string8()
{
	//bit::mystring s("hello word");
	//cout << s << endl;
	bit::mystring s1;
	bit::mystring s2;
	cin >> s1>>s2;
	cout << s1 << ' ' <<s2<<endl;
}
int main()
{
	//bit::mystring s("nnnn");
	//func(s);
	try
	{
		test_string8();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}