#define _CRT_SECURE_NO_WARNINGS

//HJ1 字符串最后一个单词的长度
#include <iostream>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	//找位置
	size_t pos = str.rfind(" ");
	//不等于全长，则能找到
	if (pos != str.npos)
	{
		cout << str.size() - pos - 1 << endl;
	}
	else
	{
		cout << str.size() << endl;
	}
}