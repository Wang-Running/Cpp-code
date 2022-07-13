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

//HJ99 自守数
//#include <stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	//计数
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
////思路：将全部转化为字符
////计算两个字符串大小及位数
////提取末尾字串比较
//
//string Num_string(int val)
//{
//	//1.先计算位数
//	//2.转换字符然后尾插，最后逆置
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
//	//计数
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

//OR86 返回小于 N 的质数个数
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	//计数
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