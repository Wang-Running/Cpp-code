#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};
//
//class Day
//{
//public:
//	Day(int year,int month,int ret,int a)
//		: _ret(ret)
//		,_a(a)
//		,_aa(a)
//	{
//		_year = year;
//		_month = month;
//	}
//private:
//	int _year;
//	int _month;
//	const int _ret;
//	int& _a;
//	A _aa;
//};
//
//int main()
//{
//	Day d1(2001,10,5,6);
//
//	return 0;
//}


//:_year(year)
//, _month(month)


//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};

//class Day
//{
//public:
//	Day(int year)
//		:_bb(year)
//		, _b(_bb)
//	{
//		cout << "����" << endl;
//	}
//	Day(const Day& d)
//	{
//		cout << "��������" << endl;
//	}
//	void Print() const
//	{
//		cout << _b << " " << _bb << endl;
//	}
//private:
//	int _b;
//	int _bb;
//};
//
//int main()
//{
//	Day d1(2001);
//	const Day& d2 = 2002;
//	d2.Print();
//	return 0;
//}

//static ��Ա

//class Day
//{
//public:
//	Day(int year)
//		:_bb(year)
//		, _b(_bb)
//	{
//		_count++;
//		cout << "����" << endl;
//	}
//	Day(const Day& d)
//	{
//		_count++;
//		cout << "��������" << endl;
//	}
//	void Print() const
//	{
//		cout << _b << " " << _bb << endl;
//	}
//	//static int _count;  //����
//	static int Getcount()
//	{
//		return _count;
//	}
//private:
//	int _b;
//	int _bb;
//	static int _count;  //����
//};
//
////����
//int Day::_count = 1;
//
//int main()
//{
//	Day d1(2001);
//	const Day& d2 = 2002;
//	d2.Print();
//	cout << d2.Getcount() << endl;
//	cout << d1.Getcount() << endl;
//	cout << Day::Getcount() << endl;
//
//	return 0;
//}

//��Ԫ��

//class A
//{
//public:
//	A(int i,int j)
//		:_a(i)
//		, _aa(j)
//	{}
//	void GetB()
//	{
//		BigB._b = _a;
//		BigB._bb = _aa;
//	}
//private:
//	int _a;
//	int _aa;
//	B BigB;
//};
//
//class B
//{
//	friend class A;
//public:
//	B(int i=22, int j=222)
//		:_b(i)
//		, _bb(j)
//	{}
//private:
//	int _b;
//	int _bb;
//};
//int main()
//{
//	A AX(1,12);
//	B BX;
//	AX.GetB();
//}

//�ڲ���
class A
{
public:
	A(int i,int j)
		:_a(i)
		, _aa(j)
	{}
	//�ڲ���B
	//Ĭ��B��A����Ԫ��
	class B
	{
	public:
		B(int i = 22, int j = 222)
			:_b(i)
			, _bb(j)
		{}
		//����ͨ��A����������˽�г�Ա
		void GetA()
		{
			A AX(12,13);
			cout << AX._a << endl;
		}
	private:
		int _b;
		int _bb;
	};
	//�ⲿ��A����ͨ���ڲ���B�Ķ��������˽�г�Ա
	void GetB()
	{
		B BX;
		//cout << BX._b << endl;
	}
private:
	int _a;
	int _aa;
};


int main()
{
	A AX(1,12);
	A::B BX;
	AX.GetB();
}
