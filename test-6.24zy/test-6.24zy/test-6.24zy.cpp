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

//344. 反转字符串
//class Solution {
//public:
//	void reverseString(vector<char>& s) {
//		vector<char>::iterator first = s.begin();
//		vector<char>::iterator tail = s.end() - 1;
//		while (first<tail)
//		{
//			char ch;
//			ch = *first;
//			*first = *tail;
//			*tail = ch;
//			first++;
//			tail--;
//		}
//	}
//};

//541. 反转字符串 II
//class Solution {
//public:
//	string reverseStr(string s, int k) {
//		size_t size = s.size();
//		//k没有越界时：
//		if (k <= size)
//		{
//			for (size_t i = 0; i<size; i += 2 * k)
//			{
//				//一个k区间换，一个k区间不换，再下一个k区间换，再下一个不换……
//				if (i + k <= size)
//				{
//					reverse(s.begin() + i, s.begin() + i + k);
//				}
//
//				//如果末尾k区间越界，则开始到末尾反转
//				else
//				{
//					reverse(s.begin() + i, s.begin() + size);
//				}
//			}
//		}
//		//k大于size，s整体反转
//		else
//		{
//			reverse(s.begin(), s.begin() + size);
//		}
//		return s;
//	}
//};

//125. 验证回文串
//class Solution {
//public:
//	bool isPalindrome(string s) {
//		string s2;
//		//先将字母和数字字符提取到一个string中
//		for (auto e : s)
//		{
//			if ('a' <= e && e <= 'z' ||
//				'A' <= e && e <= 'Z' ||
//				'0' <= e && e <= '9')
//			{
//				s2 += e;
//			}
//		}
//		string::iterator first = s2.begin();
//		string::iterator tail = s2.end() - 1;
//		//双指针，进行判断
//		while (first <= tail)
//		{
//			//1.当其中有数字字符时，直接看前后指针是否相等
//			if (('0' <= *first && *first <= '9') ||
//				'0' <= *tail && *tail <= '9')
//			{
//				if (*(first) == *(tail))
//				{
//					first++;
//					tail--;
//				}
//				else
//				{
//					return false;
//				}
//			}
//			//2.当全部为字母字符时，要判断前后字母是否相等，大小写字母相同
//			else
//			{
//				if (*(first) == *(tail) ||
//					*(first)+32 == *(tail) ||
//					*(first)-32 == *(tail))
//				{
//					first++;
//					tail--;
//				}
//				else
//				{
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//};




//415. 字符串相加
//#include<iostream>
//using namespace std;
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		int end1 = num1.size() - 1;
//		int end2 = num2.size() - 1;
//		//进位
//		int carry = 0;
//		string retstr;
//		while (end1 >= 0 || end2 >= 0)
//		{
//			int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//			int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//			int ret = val1 + val2 + carry;
//			if (ret>9)
//			{
//				ret -= 10;
//				carry = 1;
//			}
//			else
//			{
//				carry = 0;
//			}
//
//			//retstr.insert(retstr.begin(),'0'+ret);
//			retstr += ('0' + ret);
//			--end1;
//			--end2;
//		}
//		if (carry == 1)
//		{
//			//retstr.insert(retstr.begin(),'1');
//			retstr += '1';
//		}
//
//		reverse(retstr.begin(), retstr.end());
//		return retstr;
//	}
//};


//43. 字符串相乘
#include <iostream>
using namespace std;

int main()
{
	string num1 = "123";
	string num2 = "134";
	int l1 = num1.size();
	int l2 = num2.size();
	//预留出结果空间
	string res(l1 + l2, '0');
	for (int i = l1 - 1; i >= 0; i--)
	{
		for (int j = l2 - 1; j >= 0; j--)
		{
			int tmp = (res[i + j + 1] - '0') + (num1[i] - '0')*(num2[j] - '0');
			//res[i+j+1]是得数的末位
			res[i + j + 1] = tmp % 10 + '0';
			//res[i+j]是高位
			res[i + j] += tmp / 10;
		}
	}
	//for (int i = 0; i < l1 + l2; i++)
	//{
	//	if (res[i] != '0')
	//		return res.substr(i);
	//}
	return 0;
}
		

//557. 反转字符串中的单词 III
//#include <iostream>
//using namespace std;
//class Solution {
//public:
//	string reverseWords(string s) {
//		//找空格，双指针，区间反转，最后在翻转一次即可
//		string::iterator it = s.begin();
//		string::iterator begin = s.begin();
//		while (it != s.end())
//		{
//			if (*it == ' ')
//			{
//				reverse(begin, it);
//				begin = it + 1;
//			}
//			it++;
//		}
//		reverse(begin, it);
//		return s;
//	}
//};
//int main()
//{
//	string s = "Let's take LeetCode contest";
//	for (auto e:s)
//	{
//		cout << e << "";
//	}
//	cout << endl;
//	Solution A;
//	s = A.reverseWords(s);
//	for (auto e : s)
//	{
//		cout << e << "";
//	}
//	cout << endl;
//}