#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//����
void test1()
{
	//1.����һ���ն���
	string s1;
	//2.�����ַ�����ʼ��
	string s2("hello csdn");
	//3.���������ʼ��
	string s3(s2);
	string s4 = s3;
	//4.�涨���ȳ�ʼ��
	string s5("asdfghjkl", 4);
	//5.ָ���ַ�����������ʼ��
	string s6(5, 'c');

	//6.ȡ�Ѵ��ڶ�����Ӵ���ʼ��
	string s7(s2, 3, 5);
	cout << s7 << endl;
}

//��ֵ
void test2()
{
	//1.ֱ�Ӹ�ֵ
	string s1("hello");
	string s2 = ("ccc");
	s1 = s2;
	cout << s1 << endl;
	//2.���� = �����ַ���
	s1 = "sss";
	cout << s1 << endl;
	//3.���� = �ַ�
	s1 = 'w';
	cout << s1 << endl;
}

//����
void test3()
{
	string s1("abcdefg");
	//1.[�±�]����

	//�����õ���size()����,���ص����ַ������ȣ�������\0
	cout << s1.size() << endl;

	for (size_t i = 0;i < s1.size();i++)
	{
		//������[]���������Ǻ�������: s1.operator[](i);
		cout << s1[i] << " ";
	}
	cout << endl;
}
void test4()
{
	string s1("abcdefg");
	//2.����������--iterator����string�е�һ����������
	
	//�ӵ�һ��λ�ÿ�ʼ
	string::iterator it = s1.begin();
	
	//end()�ǽ���λ�õ���һ��λ��
	while (it!=s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void test7()
{
	string s1("abcdefg");
	//3.�������������--reverse_iterator

	//�ӵ�һ��λ�ÿ�ʼ
	string::reverse_iterator rit = s1.rbegin();

	//end()�ǽ���λ�õ���һ��λ��
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void test5()
{
	//3.��Χfor����
	string s1("hello csdn");
	for (auto e:s1)
	{
		cout << e << " ";
	}
	cout << endl;
}

//string�����ַ����޸�
void test6()
{
	//1.�±��޸�
	string s1("xxxxxxx");
	s1[3] = 'D';
	cout << s1 << endl;
	//2.����at�����޸�
	s1.at(0) = 'A';
	cout << s1 << endl;
}

//����
void func(const string& s)
{
	string::const_iterator it=s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

//����
void test8()
{
	string s1;
	//s1.reserve(150);
	s1.resize(150, 'x');
	//func(s1);
	for (int i = 0; i<10; i++)
	{
		s1 += "abcdefg";
		cout << s1.capacity() << endl;
	}
	cout << s1.size() << endl;
}


//int main()
//{
//	//string s1;
//	//string s2("hello");
//	////�����ַ�
//	//s1.push_back('a');
//	//cout << s1 << endl;
//
//	////1.�����ַ���-ֱ�Ӳ���
//	//s1.append("bcdf");
//	//cout << s1 << endl;
//
//	////2.����string����
//	//s1.append(s2);
//	//cout << s1 << endl;
//
//	string s1;
//	string s2("hello");
//	s1 += 'a';
//	cout << s1 << endl;
//
//	s1 += "abcdef";
//	cout << s1 << endl;
//
//	s1 += s2;
//	cout << s1 << endl;
//
//	return 0;
//}



//1.
//int main()
//{
//
//	string str("Hello Bit.");
//
//	str.reserve(111);
//
//	str.resize(5);
//
//	str.reserve(50);
//
//	cout << str.size() << ":" << str.capacity() << endl;
//
//	return 0;
//
//}

//2.c_str() ���ص���һ��ָ�������ָ�룬������ָͬ�벻ͬ
int main()
{

		string a = "hello world";
		cout << a.c_str() << endl;
		string b = a;
		cout << b.c_str() << endl;
		if (a.c_str() == b.c_str())

		{

			cout << "true" << endl;

		}

		else cout << "false" << endl;

		string c = b;

		c = "";

		if (a.c_str() == b.c_str())

		{

			cout << "true" << endl;

		}

		else cout << "false" << endl;

		a = "";

		if (a.c_str() == b.c_str())

		{

			cout << "true" << endl;

		}

		else cout << "false" << endl;

		return 0;
}