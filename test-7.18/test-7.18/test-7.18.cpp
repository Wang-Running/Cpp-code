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
class Person
{
public:
	string _name = "human";
	int arr[100];
};
class Student :virtual public Person
{
protected:
	int _sid = 123;
};
class Teacher :virtual public Person
{
protected:
	int _tid = 0123;
};
class school :public Student,public Teacher
{
protected:
	int sh = 001;
};
int main()
{
	school sch;

	sch._name = "xxx";

	Student s;
	Teacher t;
	cout << sizeof(s) << endl;
	cout << sizeof(t) << endl;
	cout << sizeof(sch) << endl;
	return 0;
}