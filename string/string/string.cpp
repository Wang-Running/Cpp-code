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
int main()
{
	test5();
	return 0;
}
