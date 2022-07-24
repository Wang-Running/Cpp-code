#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
//普通学生都能及格
//class Student {
//public:
//	virtual void test() { cout << "及格" << endl; }
//};
//class ordinary : public Student {
//public:
//	virtual void test() { cout << "良好" << endl; }
//};
//class excellent : public Student {
//public:
//	virtual void test() { cout << "优秀" << endl; }
//};
//void gotest(Student& s)
//{
//	s.test();
//}
//void gotest(Student* s)
//{
//	s->test();
//}
//int main()
//{
//	Student s1;
//	ordinary o;
//	excellent e;
//	gotest(&s1);
//	gotest(&o);
//	gotest(&e);
//	return 0;
//}

//class A
//{};
//class B : public A
//{};
//
//class Student {
//public:
//	virtual A* test() 
//	{
//		cout << "virtual A* test()" << endl; 
//		return nullptr;
//	}
//};
//class ordinary : public Student {
//public:
//	virtual B* test() 
//	{
//		cout << "virtual B* test()" << endl; 
//		return nullptr;
//	}
//};
//void gotest(Student* s)
//{
//	s->test();
//}
//int main()
//{
//	Student s1;
//	ordinary o;
//	gotest(&s1);
//	gotest(&o);
//	return 0;
//}


//class Student {
//public:
//	virtual~Student()
//	{
//		cout << "virtual ~Student()" << endl;
//	}
//};
//class ordinary : public Student {
//public:
//	~ordinary()
//	{
//		cout << "virtual ~ordinary()" << endl;
//	}
//};
//int main()
//{
//	Student* s1 = new Student;
//	delete s1;
//
//	Student* s2 = new ordinary;
//	delete s2;
//	return 0;
//}


//class Student
//{
//public:
//	virtual void test() { cout << "及格" << endl; }
//};
//class ordinary : public Student {
//public:
//	virtual void test() override { cout << "良好" << endl; }
//};
//
//int main()
//{
//	ordinary o;
//}

//抽象类
//class Student
//{
//public:
//	//纯虚函数
//	virtual void test() = 0;
//};
//class ordinary : public Student {
//public:
//	virtual void test() override { cout << "良好" << endl; }
//};
//
//int main()
//{
//	ordinary o;
//	Student* p = &o;
//	p->test();
//}

class Student
{
public:
	virtual void test(){cout << "virtual void test()" << endl;}
	virtual void test2(){cout << "virtual void test2()" << endl;}
private:
	int _sid;
};
class ordinary : public Student {
public:
	virtual void test() override {cout << "良好" << endl; }
	virtual void test3(){cout << "良好3" << endl;}
	void test4(){cout << "良好4" << endl;}
};

//打印虚函数表
typedef void(*V_FUNC) ();
void PrintVFTable(V_FUNC* a)
{
	for (size_t i = 0;a[i]!=nullptr;i++)
	{
		printf("[%d]:%p->", i, a[i]);
		V_FUNC f = a[i];
		f();
	}
}
int main()
{
	Student s;
	ordinary o;
	PrintVFTable((V_FUNC*)(*((int*)&o)));
}

//class A
//{
//public:
//	virtual void f()
//	{
//		cout << "A::f()" << endl;
//	}
//};
//class B : public A
//{
//	virtual void f()
//
//	{
//		cout << "B::f()" << endl;
//	}
//};
//int main()
//{
//	A* pa = (A*)new B;
//	pa->f();
//}


//A的构造，B的构造，再用B的func
//class A
//{
//public:
//	A() :m_iVal(0){ test(); }
//	virtual void func() { std::cout << m_iVal << " "; }
//	void test(){ func(); }
//public:
//	int m_iVal;
//};
//class B : public A
//{
//public:
//	B(){ test(); }
//	virtual void func()
//	{
//		++m_iVal;
//		std::cout << m_iVal << " ";
//	}
//};
//int main(int argc, char* argv[])
//{
//	A*p = new B;
//	p->test();
//	return 0;
//}