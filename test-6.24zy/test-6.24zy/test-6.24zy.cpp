#define _CRT_SECURE_NO_WARNINGS

//HJ1 字符串最后一个单词的长度
//#include <iostream>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin,str);
//	//找位置
//	size_t pos = str.rfind(" ");
//	//不等于全长，则能找到
//	if (pos != str.npos)
//	{
//		cout << str.size() - pos - 1 << endl;
//	}
//	else
//	{
//		cout << str.size() << endl;
//	}
//}


//387. 字符串中的第一个唯一字符
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		//哈希映射
//		//小写字母26个--计数
//		int count[26] = { 0 };
//		//s遍历，对每个字母遍历--范围for
//		for (auto e : s)
//		{
//			//字符-'a'等于相应下标位置
//			count[e - 'a']++;
//		}
//		//从头开始遍历s，找次数是1的字符，返回字符中的下标
//		for (size_t i = 0; i<s.size(); i++)
//		{
//			if (count[s[i] - 'a'] == 1)
//			{
//				return i;
//			}
//		}
//		return -1;
//	}
//};

//把字符串转换成整数

//test

//#include <iostream>
//using namespace std;
//int main()
//{
//	string str("214");
//	//一个临时整数，供给最后返回值
//	//一个临时整数，供给最后返回值
//	int sum = 0;
//	//确定有几位数
//	size_t pos = str.size();
//	for (size_t i = 0; i<str.size(); i++)
//	{
//		if (str[i] == '-' || str[i] == '+')
//		{
//			pos--;
//		}
//		else if (str[i] >= '0' && str[i] <= '9')
//		{
//			//转换为数字
//			str[i] -= '0';
//			//求整数
//			sum += str[i] * pow(10, pos - 1);
//			pos--;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	if (str[0] == '-')
//		return -sum;
//	else
//		return sum;
//}

//原题目
//class Solution {
//public:
//	int StrToInt(string str) {
//		//一个临时整数，供给最后返回值
//		int sum = 0;
//		//确定有几位数
//		size_t pos = str.size();
//		for (size_t i = 0; i<str.size(); i++)
//		{
//			if (str[i] == '-' || str[i] == '+')
//			{
//				pos--;
//			}
//			else if (str[i] >= '0' && str[i] <= '9')
//			{
//				//转换为数字
//				str[i] -= '0';
//				//求整数
//				sum += str[i] * pow(10, pos - 1);
//				pos--;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		if (str[0] == '-')
//			return -sum;
//		else
//			return sum;
//	}
//};
