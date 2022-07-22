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
//	s._name = "C程序";
//	s._age = 22;
//	//派生类对象赋值给基类对象
//	Person p;
//	p = s;
//
//	//派生类可赋值给基类引用
//	Person& pr = s;
//
//	//派生类的地址可赋给基类指针
//	Person* pp = &s;
//	cout << typeid(pp).name() << endl;
//
//	return 0;
//}


//拷贝构造
//Person(const Person& p)
//: _name(p._name)
//{
//	cout << "Person(const Person& p)" << endl;
//}
//赋值重载
//Person& operator=(const Person& p)
//{
//	cout << "Person operator=(const Person& p)" << endl;
//	if (this != &p)
//		_name = p._name;
//	return *this;
//}


//友元函数
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p , const Student& s);
//	//构造函数
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	//析构函数
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
////protected:
//private:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	//构造函数
//	Student(const char* name, int num)
//		: _num(num)
//		, Person(name)
//	{
//		cout << "Student()" << endl;
//		//_name = name;
//	}
//	//析构函数
//	~Student()
//	{
//		//Person::~Person();
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //学号
//};
////此函数要访问父类和子类的私有成员
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._num<< endl;
//}
//int main()
//{
//	Student s("张三",19);
//	Student s1("李四",20);
//	Person p;
//	s1 = s;
//	Display(p, s);
//	return 0;
//}


////拷贝构造
//Student(const Student& s)
//: Person(s)
//{
//	cout << "Student(const Student& s)" << endl;
//}
//赋值重载
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



//静态成员--传家宝
//class Person
//{
//public:
//	static int count;
//	//调用构造函数count++
//	Person()
//	{
//		count++;
//	}
//protected:
//	string _name; // 姓名
//};
//int Person::count = 0;
//class Student : public Person
//{
//protected:
//	int _num; // 学号
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

//菱形继承：数据冗余和二义性
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

//虚拟继承
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

//137. 只出现一次的数字 II
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		//先排序
//		//第一个和第二个比较，出现三次的必定是连续的
//		//不连续则i位置就是出现一次的
//		//size()-1,是防止单独的在最后一个位置，访问越界
//		sort(nums.begin(), nums.end());
//		int i = 0;
//		for (i = 0; i<nums.size() - 1; i += 3)
//		{
//			if (nums[i] != nums[i + 1])
//			{
//				return nums[i];
//			}
//		}
//		//如果在最后一个位置，则直接返回
//		return nums[i];
//	}
//};



//260. 只出现一次的数字 III
//class Solution {
//public:
//	vector<int> singleNumber(vector<int>& nums) {
//		vector<int> arr;
//		sort(nums.begin(), nums.end());
//		int i = 0;
//
//		//这里要理清情况：
//		//1.当出现一次的数都在最后时，前面数的间隔每次跳2
//		//2.每次都是与下一位置作比较，为了防止越界size()-1
//		//3.若中间有出现了一次的数，那么将其入容器，往后1，因此我们i--,然后+=2，就是走了一步
//		//4.末尾情况，看看arr满没满，没有满，那么就是：1223这种情况，指针最后到3，将3入arr
//		//满了则就是这种122344，刚刚好，返回即可
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

//JZ39 数组中出现次数超过一半的数字
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		int max = 0;
//		//找到最大值
//		for (auto e : numbers)
//		{
//			if (e>max)
//			{
//				max = e;
//			}
//		}
//		//开辟空间，初始化0，哈希绝对映射
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