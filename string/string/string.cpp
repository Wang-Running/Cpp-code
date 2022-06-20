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
int main()
{
	test5();
	return 0;
}
