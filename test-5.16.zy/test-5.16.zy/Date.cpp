#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"

// 赋值运算符重载

// d2 = d3 -> d2.operator=(&d2, d3)

Date& Date::operator=(const Date& d)
{
	if (*this != d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}



//// 析构函数
//
//~Date()




//// 日期+=天数

//Date& operator+=(int day);



// 日期+天数

Date Date::operator+(int day)
{
	Date ret(*this);
	ret._day += day;
	//this->_day += day;
	return ret;
}



//// 日期-天数

//Date operator-(int day);



//// 日期-=天数

//Date& operator-=(int day);



//// 前置++

//Date& operator++();



//// 后置++

//Date operator++(int);



//// 后置--

//Date operator--(int);



//// 前置--

//Date& operator--();

// >运算符重载

bool Date::operator>(const Date& d)
{
	//if ((_year > d._year) ||
	//	(_year == d._year) && (_month > d._month) ||
	//	(_year == d._year) && (_month == d._month) && (_day > d._day))
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	return !(*this <= d);
}


// ==运算符重载

//参数：看运算符来定:两个相比较，那么就有两个形参
//返回值：看运算后的结构，比较相等返回真假即可，即bool

//这里隐含参数为this指针
bool Date::operator==(const Date& d)
{
	return _year == d._year&&
		_month == d._month&&
		_day == d._day;
}



// >=运算符重载

inline bool Date::operator >= (const Date& d)
{
	//if ((_year > d._year) ||
	//	(_year == d._year) && (_month > d._month) ||
	//	(_year == d._year) && (_month == d._month) && (_day >= d._day))
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	return *this > d || *this == d;
	//return !(*this < d);
}



// <运算符重载

bool Date::operator < (const Date& d)
{
	if ((_year < d._year) ||
		(_year == d._year) && (_month < d._month) ||
		(_year == d._year) && (_month == d._month) && (_day < d._day))
	{
		return true;
	}
	else
	{
		return false;
	}
}



// <=运算符重载

bool Date::operator <= (const Date& d)
{
	//if ((_year < d._year) ||
	//	(_year == d._year) && (_month < d._month) ||
	//	(_year == d._year) && (_month == d._month) && (_day <= d._day))
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	return *this < d || *this == d;
}



// !=运算符重载

bool Date::operator != (const Date& d)
{
	/*if ((_year != d._year) ||
	(_year == d._year) && (_month != d._month) ||
	(_year == d._year) && (_month == d._month) && (_day != d._day))
	{
	return true;
	}
	else
	{
	return false;
	}*/
	return !(*this == d);
}



// 日期-日期 返回天数

//int operator-(const Date& d);

int Date::GetMonthDay(int year, int month)
{
	assert(year >= 0 && month>0 && month<13);
	static int MDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && Leapyear(year))
	{
		return 29;
	}
	else
	{
		return MDay[month];
	}
}