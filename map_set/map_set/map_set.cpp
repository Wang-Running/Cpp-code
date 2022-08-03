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
		cout << "在" << endl;
		s.erase(pos);
		cout << "删除成功" << endl;
	}

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
}

//查找
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
		cout << "在" << endl;
	}
	if (s.find(6)!=s.end())
	{
		cout << "在" << endl;
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
	//cout << "9的个数:" << s.count(9) << endl;
	cout << "8的个数:" << s.count(8) << endl;
	//cout << "20的个数:" << s.count(20) << endl;

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

	//声明类型，匿名对象
	m.insert(pair<int, string>(1, "a"));

	//创建对象，插入对象
	pair<int, string> kv(2, "b");
	m.insert(kv);

	//调用函数模板make_pair,不用声明pair类型
	m.insert(make_pair(3, "c"));
}

//find 插入计数
void test9()
{
	//将以下数据插入map中，并且计数
	string arr[] = { "马克杯", "玻璃杯", "塑料杯", "玻璃杯", "玻璃杯", "玻璃杯", "马克杯", "马克杯", "塑料杯", "玻璃杯" };
	map<string, int> m;
	for (auto& str : arr)
	{
		map<string, int>::iterator it = m.find(str);
		//找到返回的是key_type（即pair的第一个数据）的迭代器
		if (it != m.end())
		{
			it->second++;    //找到pair的second( value_type ) 自增 1 
		}
		else     //没找到说明没有，则插入
		{
			m.insert(make_pair(str, 1));
		}
	}
	//遍历
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}
}

//insert 插入计数
void test10()
{
	//将以下数据插入map中，并且计数
	string arr[] = { "马克杯", "玻璃杯", "塑料杯", "玻璃杯", "玻璃杯", "玻璃杯", "马克杯", "马克杯", "塑料杯", "玻璃杯" };
	map<string, int> m;
	for (auto& str : arr)
	{
		auto ret = m.insert(make_pair(str, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
	//遍历
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}
}

//[] 插入+计数
void test11()
{
	//将以下数据插入map中，并且计数
	string arr[] = { "马克杯", "玻璃杯", "塑料杯", "玻璃杯", "玻璃杯", "玻璃杯", "马克杯", "马克杯", "塑料杯", "玻璃杯" };
	map<string, int> m;
	for (auto& str : arr)
	{
		m[str]++;
	}
	//遍历
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




//692. 前K个高频单词
//class Solution {
//public:
//	typedef map<string, int>::iterator CountTter;
//
//	struct IterCompare
//	{
//		bool operator()(CountTter it1, CountTter it2)
//		{                                                               //用sort，下面手动消除不稳定
//			return it1->second > it2->second;            //return it1->second > it2->second || (it1->second ==it2->second && it1->first < it2->first);
//		}
//	};
//
//	vector<string> topKFrequent(vector<string>& words, int k) {
//		map<string, int> countmap;
//		//插入并计数
//		for (auto& str : words)
//		{
//			countmap[str]++;
//		}
//
//		//将迭代器放入vector，排序
//		vector<CountTter> v;
//		CountTter it = countmap.begin();
//		while (it != countmap.end())
//		{
//			v.push_back(it);
//			it++;
//		}
//
//		//迭代器不支持排序，写一个迭代器比较的仿函数--- sort不稳定
//		stable_sort(v.begin(), v.end(), IterCompare());
//		//将排好序的每个pair中的first放入ret中
//		vector<string> ret;
//		for (size_t i = 0; i < k; i++)
//		{
//			ret.push_back(v[i]->first);
//		}
//		return ret;
//	}
//};

//KY264 单词识别
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
//		int slow = 0;   //单词的起始下标
//		string s;       //存放单个单词
//		for (int i = 0; i < str.size(); i++)
//		{
//			//大写变小写
//			if ('A' <= str[i] && str[i] <= 'Z')
//			{
//				str[i] += 32;
//			}
//			//取单词放入mp中，插入+计数+自动降序排序
//			if (str[i] == ' ' || str[i] == '.')
//			{
//				int num = i - slow;     //单词大小
//				s = str.substr(slow, num);  //通过单词起始下标和大小取出来
//				mp[s]++;
//				slow = i + 1;  //跳过空格到下一个单词的起始位置
//			}
//		}
//
//		//上述已经按字典序排好了---下面将次数大的放在前面
//		//注意次数出现相等，防止去重，要用multimap
//		//手动更改为降序
//		multimap<int, string, greater<int>> intsort;
//		for (const auto& e : mp)
//		{
//			//插入+排序
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