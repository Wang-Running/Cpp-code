#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

//class Person
//{
//public:
//	void func()
//	{
//		cout << "P:func" << endl;
//	}
//	string _name = "C++";
//	int _age = 18;
//};
//class Student :public Person
//{
//public:
//	void func()
//	{
//		cout << "S:func" << endl;
//	}
//protected:
//	int _stuid;
//	int _age = 45;
//};
//int main()
//{
//	Student s;
//	s.func();
//	s.Person::func();
//	return 0;
//}

//int main()
//{
//	Student s;
//	s._name = "C����";
//	s._age = 22;
//	//���������ֵ���������
//	Person p;
//	p = s;
//
//	//������ɸ�ֵ����������
//	Person& pr = s;
//
//	//������ĵ�ַ�ɸ�������ָ��
//	Person* pp = &s;
//	cout << typeid(pp).name() << endl;
//
//	return 0;
//}


//��������
//Person(const Person& p)
//: _name(p._name)
//{
//	cout << "Person(const Person& p)" << endl;
//}
//��ֵ����
//Person& operator=(const Person& p)
//{
//	cout << "Person operator=(const Person& p)" << endl;
//	if (this != &p)
//		_name = p._name;
//	return *this;
//}


//��Ԫ����
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p , const Student& s);
//	//���캯��
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	//��������
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
////protected:
//private:
//	string _name; // ����
//};
//class Student : public Person
//{
//public:
//	//���캯��
//	Student(const char* name, int num)
//		: _num(num)
//		, Person(name)
//	{
//		cout << "Student()" << endl;
//		//_name = name;
//	}
//	//��������
//	~Student()
//	{
//		//Person::~Person();
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //ѧ��
//};
////�˺���Ҫ���ʸ���������˽�г�Ա
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._num<< endl;
//}
//int main()
//{
//	Student s("����",19);
//	Student s1("����",20);
//	Person p;
//	s1 = s;
//	Display(p, s);
//	return 0;
//}


////��������
//Student(const Student& s)
//: Person(s)
//{
//	cout << "Student(const Student& s)" << endl;
//}
//��ֵ����
//Student& operator=(const Student& s)
//{
//	cout << "Student& operator= (const Student& s)" << endl;
//	if (this != &s)
//	{
//		Person::operator =(s);
//		_num = s._num;
//	}
//	return *this;
//}



//��̬��Ա--���ұ�
//class Person
//{
//public:
//	static int count;
//	//���ù��캯��count++
//	Person()
//	{
//		count++;
//	}
//protected:
//	string _name; // ����
//};
//int Person::count = 0;
//class Student : public Person
//{
//protected:
//	int _num; // ѧ��
//};
//int main()
//{
//	Person p;
//	Student s;
//	Student s1;
//	Student s2;
//	Person p1;
//	cout << &Person::count << endl;
//	cout << &Student::count << endl;
//	cout << &s.count << endl;
//	cout << &p1.count << endl;
//}

//���μ̳У���������Ͷ�����
//class Person
//{
//public:
//	string _name = "human";
//	int arr[100];
//};
//class Student :virtual public Person
//{
//protected:
//	int _sid = 123;
//};
//class Teacher :virtual public Person
//{
//protected:
//	int _tid = 0123;
//};
//class school :public Student,public Teacher
//{
//protected:
//	int sh = 001;
//};
//int main()
//{
//	school sch;
//
//	sch._name = "xxx";
//
//	Student s;
//	Teacher t;
//	cout << sizeof(s) << endl;
//	cout << sizeof(t) << endl;
//	cout << sizeof(sch) << endl;
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//class B :public A
//{
//public:
//	int _b;
//};
//class C :public A
//{
//public:
//	int _c;
//};
//class D :public B,public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}

//����̳�
//class A
//{
//public:
//	int _a;
//};
//class B :virtual public A
//{
//public:
//	int _b;
//};
//class C :virtual public A
//{
//public:
//	int _c;
//};
//class D :public B,public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}

//class Base1
//{ 
//public: 
//	int _b1;
//};
//
//class Base2 
//{ 
//public: 
//	int _b2;
//};
//
//class Derive : public Base1, public Base2
//
//{
//public: 
//	int _d;
//};
//
//
//
//int main(){
//
//
//
//	Derive d;
//
//	Base1* p1 = &d;
//
//	Base2* p2 = &d;
//
//	Derive* p3 = &d;
//
//	return 0;
//
//}

#include <iostream>
#include <vector>
#include<algorithm>
//using namespace std;
//
//int main()
//{
//	vector<int> nums;
//	nums.push_back(2);
//	nums.push_back(2);
//	nums.push_back(3);
//	nums.push_back(2);
//	sort(nums.begin(), nums.end());
//	int i = 0;
//	for (i = 0; i<nums.size() - 1; i += 3)
//	{
//		if (nums[i] != nums[i + 1])
//		{
//			return nums[i];
//		}
//	}
//	return nums[i];
//	return 0;
//}

//137. ֻ����һ�ε����� II
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		//������
//		//��һ���͵ڶ����Ƚϣ��������εıض���������
//		//��������iλ�þ��ǳ���һ�ε�
//		//size()-1,�Ƿ�ֹ�����������һ��λ�ã�����Խ��
//		sort(nums.begin(), nums.end());
//		int i = 0;
//		for (i = 0; i<nums.size() - 1; i += 3)
//		{
//			if (nums[i] != nums[i + 1])
//			{
//				return nums[i];
//			}
//		}
//		//��������һ��λ�ã���ֱ�ӷ���
//		return nums[i];
//	}
//};



//260. ֻ����һ�ε����� III
//class Solution {
//public:
//	vector<int> singleNumber(vector<int>& nums) {
//		vector<int> arr;
//		sort(nums.begin(), nums.end());
//		int i = 0;
//
//		//����Ҫ���������
//		//1.������һ�ε����������ʱ��ǰ�����ļ��ÿ����2
//		//2.ÿ�ζ�������һλ�����Ƚϣ�Ϊ�˷�ֹԽ��size()-1
//		//3.���м��г�����һ�ε�������ô����������������1���������i--,Ȼ��+=2����������һ��
//		//4.ĩβ���������arr��û����û��������ô���ǣ�1223���������ָ�����3����3��arr
//		//�������������122344���ոպã����ؼ���
//
//		for (i; i<nums.size() - 1; i += 2)
//		{
//			if (nums[i] != nums[i + 1])
//			{
//				arr.push_back(nums[i]);
//				i--;
//			}
//		}
//		if (arr.size()<2)
//		{
//			arr.push_back(nums[i]);
//		}
//		return arr;
//	}
//};
//int main()
//{
//	vector<int> arr;
//	vector<int> nums;
//	nums.push_back(0);
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(2);
//		sort(nums.begin(), nums.end());
//		int i = 0;
//		for (i;i<nums.size()-1;i++)
//		{
//			if (nums[i]!=nums[i+1])
//			{
//				arr.push_back(nums[i]);
//			}
//		}
//		if (arr.size()<2)
//		{
//			arr.push_back(nums[i - 1]);
//		}
//		return 0;
//}

//JZ39 �����г��ִ�������һ�������
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		int max = 0;
//		//�ҵ����ֵ
//		for (auto e : numbers)
//		{
//			if (e>max)
//			{
//				max = e;
//			}
//		}
//		//���ٿռ䣬��ʼ��0����ϣ����ӳ��
//		vector<int> arr;
//		arr.resize(max + 1, 0);
//		for (auto e : numbers)
//		{
//			arr[e]++;
//		}
//		for (int i = 0; i<arr.size(); i++)
//		{
//			if (arr[i]>(numbers.size() / 2))
//			{
//				return i;
//			}
//		}
//		return 0;
//	}
//};