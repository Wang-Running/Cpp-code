#define _CRT_SECURE_NO_WARNINGS

//HJ1 �ַ������һ�����ʵĳ���
#include <iostream>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	//��λ��
	size_t pos = str.rfind(" ");
	//������ȫ���������ҵ�
	if (pos != str.npos)
	{
		cout << str.size() - pos - 1 << endl;
	}
	else
	{
		cout << str.size() << endl;
	}
}