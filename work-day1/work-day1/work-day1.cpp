#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	char a = 101;
//	char b = 128;
//	int sum = 200;
//	a += 27;
//	sum += a;
//	printf("%d\n", sum);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int value = 1024;
//	char* ch = (char*)(&value);
//	char condition = *((char*)(&value));
//	if (condition)
//		value += 1;
//	condition = *((char*)(&value));
//	if (condition)
//		value += 1;
//	condition = *((char*)(&value));
//	printf("%d %d", value, condition);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//void func(char para[100])
//{
//	void *p = malloc(100);
//	printf("%d, %d\n", sizeof(para), sizeof(p));
//}
//int main()
//{
//	char arr[100];
//	func(arr);
//}

//#include <stdio.h>
//void func(char *p)
//{
//	p = p + 1;
//}
//int main()
//{
//	char s[] = { '1', '2', '3', '4' };
//	func(s);
//	printf("%c", *s);
//	return 0;
//}

//HJ99 ������
//#include <stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	//����
//	int count = 0;
//	for (int i = 0; i <= n; i++)
//	{
//		int num = i*i;
//		if (num % 10000 == i || num % 1000 == i || num % 100 == i || num % 10 == i)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
////˼·����ȫ��ת��Ϊ�ַ�
////���������ַ�����С��λ��
////��ȡĩβ�ִ��Ƚ�
//
//string Num_string(int val)
//{
//	//1.�ȼ���λ��
//	//2.ת���ַ�Ȼ��β�壬�������
//	string s;
//	int bit = 0;
//	while (val)
//	{
//		bit++;
//		s += (val % 10 + '0');
//		val = (val - (val % 10)) / 10;
//	}
//	reverse(s.begin(), s.end());
//	return s;
//}
//
//int main(){
//	//����
//	int count = 0;
//	int n;
//	cin >> n;
//	for (int i = 0; i <= n; i++)
//	{
//		int num = i*i;
//		if (i == num)
//		{
//			count++;
//		}
//		else
//		{
//			string s1 = Num_string(i);
//			string s2 = Num_string(num);
//			size_t size1 = s1.size();
//			size_t size2 = s2.size();
//			string s3 = s2.substr(size2 - size1, size1);
//			if (s1 == s3)
//			{
//				count++;
//			}
//		}
//	}
//	cout << count << endl;
//}

//OR86 ����С�� N ����������
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	//����
	int count = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			if (j<i && i % j == 0)
			{
				break;
			}
			if (i == j)
			{
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}