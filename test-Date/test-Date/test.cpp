#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"


void func(const Date& d)
{
	d.Print(); // d.Print(&d) -> const Date*
	cout << &d << endl;
}


void Testone()
{
	Date d1;     //
	d1.Print(); //Print函数在类中，编译器会转化为:d1.Print(&d1) 
	            //在Print函数的形参中 this指针的类型是 Date* const this
	func(d1);
	(d1 + 30).Print();
	cout << &d1 << endl;
}


//int main()
//{
//	Date d4(2008, 11, 28);
//	d4.Print();
//	Date d3;
//	d3.Print();
//	d3 = d4;
//	d3.Print();
//
//	//d4.Print();
//	//d4 -= -1;
//	//d4.Print();
//	//Testone();
//	//func(d4);
//	return 0;
//}

//ostream 是属于std中的，我们使用时要指明作用域
//void operator<< (std::ostream& out, const Date& d)
//{
//	out << d.Getyear() << "-" << d.Getmonth() << "-" << d.Getday() << endl;
//}

std::ostream& operator<< (std::ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}
std::istream& operator>> (std::istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day ;
	return in;
}

int main()
{
	Date d4(2022, 5, 24);
	Date d5;
	cout << d4 <<d5;
	cout;
	//cin >> d5;
	//cout << d5;

	return 0;
}

//int main()
//{
//	//int a = 4;
//	//cout << a;
//	//cout << "--";
//	//cout.operator<<(a);
//
//	//Date d4(2022,5,24);
//	//d4 << cout ;
//	//cout << endl;
//	//d4.operator<<(cout);
//	//cout << endl;
//	//operator<<(cout,d4);
//
//	Date d4(2022, 5, 24);
//	Date d5;
//	cout << d4 <<d5;
//
//	return 0;
//}