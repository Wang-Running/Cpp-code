#define _CRT_SECURE_NO_WARNINGS

//vector ��֧��ͷ��ͷɾ

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//��ʼ��
void test_vector1()
{
	vector<int> v1;
	v1.push_back(12);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(6);

	vector<string> v2;
	v2.push_back("���");
	v2.push_back("�Ÿ�");

	//�����������ʼ��
	vector<string> v3(v2.begin(), v2.end());
}

//����
void test_vector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	//1.�±����
	for (size_t i = 0;i<v.size();i++)
	{
		v[i] += 1;
		cout << v[i] << "";
	}
	cout << endl;

	//2.������
	vector<int>::iterator it = v.begin();
	while (it!=v.end())
	{
		*it -= 1;
		cout << *it << "";
		it++;
	}
	cout << endl;

	//3.��Χfor
	for (auto e:v)
	{
		cout << e << "";
	}
	cout << endl;
}

//����--����
void test_vector3()
{
	vector<int> v;
	//����
	v.reserve(100);
	//����+��ʼ��+��ı�size��С+����ı�����
	v.resize(50,1);
	//����--��������������size���--��������
	v.shrink_to_fit();
}

//����--��֧���±�
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

	//ɾ��
	v.erase(v.begin());
	v.erase(v.begin());
	v.erase(v.begin());
	for (auto e : v)
	{
		cout << e << "";
	}
	cout << endl;
}

//����--�õ��㷨ͷ�ļ� algorithm
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
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	v.erase(pos);
	for (auto e : v)
	{
		cout << e << "";
	}
	cout << endl;
}

//����
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

	//Ĭ��������
	sort(v.begin(), v.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	//Ҫ�Ž����õ��º���--ͷ�ļ�functional
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