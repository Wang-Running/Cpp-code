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

//344. ��ת�ַ���
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

//541. ��ת�ַ��� II
//class Solution {
//public:
//	string reverseStr(string s, int k) {
//		size_t size = s.size();
//		//kû��Խ��ʱ��
//		if (k <= size)
//		{
//			for (size_t i = 0; i<size; i += 2 * k)
//			{
//				//һ��k���任��һ��k���䲻��������һ��k���任������һ����������
//				if (i + k <= size)
//				{
//					reverse(s.begin() + i, s.begin() + i + k);
//				}
//
//				//���ĩβk����Խ�磬��ʼ��ĩβ��ת
//				else
//				{
//					reverse(s.begin() + i, s.begin() + size);
//				}
//			}
//		}
//		//k����size��s���巴ת
//		else
//		{
//			reverse(s.begin(), s.begin() + size);
//		}
//		return s;
//	}
//};


//415. �ַ������
//#include<iostream>
//using namespace std;
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		int end1 = num1.size() - 1;
//		int end2 = num2.size() - 1;
//		//��λ
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

//