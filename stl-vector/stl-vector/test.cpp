#define _CRT_SECURE_NO_WARNINGS

//vector 不支持头插头删

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//初始化
void test_vector1()
{
	vector<int> v1;
	v1.push_back(12);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(6);

	vector<string> v2;
	v2.push_back("李白");
	v2.push_back("杜甫");

	//迭代器区间初始化
	vector<string> v3(v2.begin(), v2.end());
}

//遍历
void test_vector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	//1.下标遍历
	for (size_t i = 0;i<v.size();i++)
	{
		v[i] += 1;
		cout << v[i] << "";
	}
	cout << endl;

	//2.迭代器
	vector<int>::iterator it = v.begin();
	while (it!=v.end())
	{
		*it -= 1;
		cout << *it << "";
		it++;
	}
	cout << endl;

	//3.范围for
	for (auto e:v)
	{
		cout << e << "";
	}
	cout << endl;
}

//扩容--缩容
void test_vector3()
{
	vector<int> v;
	//扩容
	v.reserve(100);
	//扩容+初始化+会改变size大小+不会改变容量
	v.resize(50,1);
	//瘦身--将容量调整到和size相等--少用慎用
	v.shrink_to_fit();
}

//插入--不支持下标
void test_vector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	v.insert(v.begin(), -1);
	v.insert(v.begin(), -2);
	v.insert(v.begin(), -3);
	for (auto e : v)
	{
		cout << e << "";
	}
	cout << endl;

	//删除
	v.erase(v.begin());
	v.erase(v.begin());
	v.erase(v.begin());
	for (auto e : v)
	{
		cout << e << "";
	}
	cout << endl;
}

//查找--用到算法头文件 algorithm
void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	v.insert(v.begin(), -1);
	v.insert(v.begin(), -2);
	v.insert(v.begin(), -3);
	for (auto e : v)
	{
		cout << e << "";
	}
	cout << endl;

	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	auto pos = find(v.begin(), v.end(), 3);
	if (pos!=v.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	v.erase(pos);
	for (auto e : v)
	{
		cout << e << "";
	}
	cout << endl;
}

//排序
void test_vector6()
{
	vector<int> v;
	v.push_back(14);
	v.push_back(2);
	v.push_back(4);
	v.push_back(9);
	v.push_back(6);
	v.push_back(7);
	v.push_back(5);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//默认是升序
	sort(v.begin(), v.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//要排降序，用到仿函数--头文件functional
	sort(v.begin(), v.end(), greater<int>());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test_vector6();
	return 0;
}