#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//构造
void test1()
{
	//1.构造一个空对象
	string s1;
	//2.常量字符串初始化
	string s2("hello csdn");
	//3.拷贝构造初始化
	string s3(s2);
	string s4 = s3;
	//4.规定长度初始化
	string s5("asdfghjkl", 4);
	//5.指定字符，及个数初始化
	string s6(5, 'c');

	//6.取已存在对象的子串初始化
	string s7(s2, 3, 5);
	cout << s7 << endl;
}

//赋值
void test2()
{
	//1.直接赋值
	string s1("hello");
	string s2 = ("ccc");
	s1 = s2;
	cout << s1 << endl;
	//2.对象 = 常量字符串
	s1 = "sss";
	cout << s1 << endl;
	//3.对象 = 字符
	s1 = 'w';
	cout << s1 << endl;
}

//遍历
void test3()
{
	string s1("abcdefg");
	//1.[下标]遍历

	//这里用到了size()函数,返回的是字符串长度，不包含\0
	cout << s1.size() << endl;

	for (size_t i = 0;i < s1.size();i++)
	{
		//这里用[]，本质上是函数重载: s1.operator[](i);
		cout << s1[i] << " ";
	}
	cout << endl;
}
void test4()
{
	string s1("abcdefg");
	//2.迭代器遍历--iterator属于string中的一个内置类型
	
	//从第一个位置开始
	string::iterator it = s1.begin();
	
	//end()是结束位置的下一个位置
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
	//3.迭代器反向遍历--reverse_iterator

	//从第一个位置开始
	string::reverse_iterator rit = s1.rbegin();

	//end()是结束位置的下一个位置
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void test5()
{
	//3.范围for遍历
	string s1("hello csdn");
	for (auto e:s1)
	{
		cout << e << " ";
	}
	cout << endl;
}

//string访问字符并修改
void test6()
{
	//1.下标修改
	string s1("xxxxxxx");
	s1[3] = 'D';
	cout << s1 << endl;
	//2.访问at函数修改
	s1.at(0) = 'A';
	cout << s1 << endl;
}

//传参
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

//容量
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
//	////插入字符
//	//s1.push_back('a');
//	//cout << s1 << endl;
//
//	////1.插入字符串-直接插入
//	//s1.append("bcdf");
//	//cout << s1 << endl;
//
//	////2.插入string对象
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

//2.c_str() 返回的是一个指针数组的指针，内容相同指针不同
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