#define _CRT_SECURE_NO_WARNINGS

//HJ1 �ַ������һ�����ʵĳ���
//#include <iostream>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin,str);
//	//��λ��
//	size_t pos = str.rfind(" ");
//	//������ȫ���������ҵ�
//	if (pos != str.npos)
//	{
//		cout << str.size() - pos - 1 << endl;
//	}
//	else
//	{
//		cout << str.size() << endl;
//	}
//}


//387. �ַ����еĵ�һ��Ψһ�ַ�
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		//��ϣӳ��
//		//Сд��ĸ26��--����
//		int count[26] = { 0 };
//		//s��������ÿ����ĸ����--��Χfor
//		for (auto e : s)
//		{
//			//�ַ�-'a'������Ӧ�±�λ��
//			count[e - 'a']++;
//		}
//		//��ͷ��ʼ����s���Ҵ�����1���ַ��������ַ��е��±�
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

//���ַ���ת��������

//test

//#include <iostream>
//using namespace std;
//int main()
//{
//	string str("214");
//	//һ����ʱ������������󷵻�ֵ
//	//һ����ʱ������������󷵻�ֵ
//	int sum = 0;
//	//ȷ���м�λ��
//	size_t pos = str.size();
//	for (size_t i = 0; i<str.size(); i++)
//	{
//		if (str[i] == '-' || str[i] == '+')
//		{
//			pos--;
//		}
//		else if (str[i] >= '0' && str[i] <= '9')
//		{
//			//ת��Ϊ����
//			str[i] -= '0';
//			//������
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

//ԭ��Ŀ
//class Solution {
//public:
//	int StrToInt(string str) {
//		//һ����ʱ������������󷵻�ֵ
//		int sum = 0;
//		//ȷ���м�λ��
//		size_t pos = str.size();
//		for (size_t i = 0; i<str.size(); i++)
//		{
//			if (str[i] == '-' || str[i] == '+')
//			{
//				pos--;
//			}
//			else if (str[i] >= '0' && str[i] <= '9')
//			{
//				//ת��Ϊ����
//				str[i] -= '0';
//				//������
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
