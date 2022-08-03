#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

void test1()
{
	set<int> s;
	s.insert(5);
	s.insert(5);
	s.insert(6);
	s.insert(8);
	s.insert(5);
	s.insert(8);
	s.insert(9);
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
}

void test2()
{
	set<int> s;
	s.insert(5);
	s.insert(6);
	s.insert(8);
	s.insert(5);
	s.insert(8);
	s.insert(9);
	s.insert(1);
	cout << s.erase(1) << endl;
	cout << s.erase(5) << endl;;
	cout << s.erase(100) << endl;;
	for (auto &e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	set<int>::iterator pos = s.find(6);
	if (pos!=s.end())
	{
		cout << "��" << endl;
		s.erase(pos);
		cout << "ɾ���ɹ�" << endl;
	}

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
}

//����
void test3()
{
	set<int> s;
	s.insert(5);
	s.insert(6);
	s.insert(8);
	s.insert(5);
	s.insert(8);
	s.insert(9);
	s.insert(1);
	
	if (s.count(6))
	{
		cout << s.count(6) << endl;
		cout << s.count(100) << endl;
		cout << "��" << endl;
	}
	if (s.find(6)!=s.end())
	{
		cout << "��" << endl;
	}
}

//lower_bound
void test4()
{
	set<int> s;
	s.insert(5);
	s.insert(6);
	s.insert(8);
	s.insert(5);
	s.insert(8);
	s.insert(9);
	s.insert(1);
	for (auto &e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	set<int>::iterator it1 = s.lower_bound(4);
	//set<int>::iterator it2 = s.lower_bound(6);
	s.erase(it1, s.end());
	for (auto &e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

//upper_bound
void test5()
{
	set<int> s;
	s.insert(5);
	s.insert(6);
	s.insert(8);
	s.insert(5);
	s.insert(8);
	s.insert(9);
	s.insert(1);
	set<int>::iterator it1 = s.lower_bound(1);
	set<int>::iterator it2 = s.upper_bound(8);
	s.erase(it1, it2);
	for (auto &e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

//multiset
void test6()
{
	multiset<int> s;
	s.insert(5);
	s.insert(6);
	s.insert(8);
	s.insert(5);
	s.insert(8);
	s.insert(9);
	s.insert(1);
	//cout << "9�ĸ���:" << s.count(9) << endl;
	cout << "8�ĸ���:" << s.count(8) << endl;
	//cout << "20�ĸ���:" << s.count(20) << endl;

	cout << s.erase(8) << endl;
	for (auto &e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	
}

//multiset--find
void test7()
{
	multiset<int> s;
	s.insert(8);
	s.insert(5);
	s.insert(6);
	s.insert(8);
	s.insert(5);
	s.insert(8);
	s.insert(9);
	s.insert(1);
	s.insert(8);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	multiset<int>::iterator pos = s.find(8);

	while (pos!=s.end())
	{
		cout << *pos << " ";
		pos++;
	}
	cout << endl;
}

//map--insert
void test8()
{
	map<int,string> m;

	//�������ͣ���������
	m.insert(pair<int, string>(1, "a"));

	//�������󣬲������
	pair<int, string> kv(2, "b");
	m.insert(kv);

	//���ú���ģ��make_pair,��������pair����
	m.insert(make_pair(3, "c"));
}

//find �������
void test9()
{
	//���������ݲ���map�У����Ҽ���
	string arr[] = { "��˱�", "������", "���ϱ�", "������", "������", "������", "��˱�", "��˱�", "���ϱ�", "������" };
	map<string, int> m;
	for (auto& str : arr)
	{
		map<string, int>::iterator it = m.find(str);
		//�ҵ����ص���key_type����pair�ĵ�һ�����ݣ��ĵ�����
		if (it != m.end())
		{
			it->second++;    //�ҵ�pair��second( value_type ) ���� 1 
		}
		else     //û�ҵ�˵��û�У������
		{
			m.insert(make_pair(str, 1));
		}
	}
	//����
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}
}

//insert �������
void test10()
{
	//���������ݲ���map�У����Ҽ���
	string arr[] = { "��˱�", "������", "���ϱ�", "������", "������", "������", "��˱�", "��˱�", "���ϱ�", "������" };
	map<string, int> m;
	for (auto& str : arr)
	{
		auto ret = m.insert(make_pair(str, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
	//����
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}
}

//[] ����+����
void test11()
{
	//���������ݲ���map�У����Ҽ���
	string arr[] = { "��˱�", "������", "���ϱ�", "������", "������", "������", "��˱�", "��˱�", "���ϱ�", "������" };
	map<string, int> m;
	for (auto& str : arr)
	{
		m[str]++;
	}
	//����
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}
}



//int main()
//{
//	test11();
//	return 0;
//}




//692. ǰK����Ƶ����
//class Solution {
//public:
//	typedef map<string, int>::iterator CountTter;
//
//	struct IterCompare
//	{
//		bool operator()(CountTter it1, CountTter it2)
//		{                                                               //��sort�������ֶ��������ȶ�
//			return it1->second > it2->second;            //return it1->second > it2->second || (it1->second ==it2->second && it1->first < it2->first);
//		}
//	};
//
//	vector<string> topKFrequent(vector<string>& words, int k) {
//		map<string, int> countmap;
//		//���벢����
//		for (auto& str : words)
//		{
//			countmap[str]++;
//		}
//
//		//������������vector������
//		vector<CountTter> v;
//		CountTter it = countmap.begin();
//		while (it != countmap.end())
//		{
//			v.push_back(it);
//			it++;
//		}
//
//		//��������֧������дһ���������Ƚϵķº���--- sort���ȶ�
//		stable_sort(v.begin(), v.end(), IterCompare());
//		//���ź����ÿ��pair�е�first����ret��
//		vector<string> ret;
//		for (size_t i = 0; i < k; i++)
//		{
//			ret.push_back(v[i]->first);
//		}
//		return ret;
//	}
//};

//KY264 ����ʶ��
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//int main()
//{
//	string str;
//	map<string, int> mp;
//	while (getline(cin, str))
//	{
//		int slow = 0;   //���ʵ���ʼ�±�
//		string s;       //��ŵ�������
//		for (int i = 0; i < str.size(); i++)
//		{
//			//��д��Сд
//			if ('A' <= str[i] && str[i] <= 'Z')
//			{
//				str[i] += 32;
//			}
//			//ȡ���ʷ���mp�У�����+����+�Զ���������
//			if (str[i] == ' ' || str[i] == '.')
//			{
//				int num = i - slow;     //���ʴ�С
//				s = str.substr(slow, num);  //ͨ��������ʼ�±�ʹ�Сȡ����
//				mp[s]++;
//				slow = i + 1;  //�����ո���һ�����ʵ���ʼλ��
//			}
//		}
//
//		//�����Ѿ����ֵ����ź���---���潫������ķ���ǰ��
//		//ע�����������ȣ���ֹȥ�أ�Ҫ��multimap
//		//�ֶ�����Ϊ����
//		multimap<int, string, greater<int>> intsort;
//		for (const auto& e : mp)
//		{
//			//����+����
//			intsort.insert(make_pair(e.second, e.first));
//		}
//
//		for (const auto& e : intsort)
//		{
//			cout << e.second << ":" << e.first << endl;
//		}
//
//	}
//	return 0;
//}