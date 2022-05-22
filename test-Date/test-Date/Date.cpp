#define _CRT_SECURE_NO_WARNINGS


#include "Date.h"

// 赋值运算符重载

// d2 = d3 -> d2.operator=(&d2, d3)

Date& Date::operator=(const Date& d)
{
	cout << "赋值" << endl;
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




// 日期+=天数

Date& Date::operator+=(int day)
{
	if (day<0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day>GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
	//*this = *this + day;
	//return *this;
}

// 日期+天数
Date Date::operator+(int day)
{
	Date ret(*this);
	//ret._day += day;
	//while (ret._day>GetMonthDay(ret._year, ret._month))
	//{
	//	ret._day -= GetMonthDay(ret._year, ret._month);
	//	ret._month++;
	//	if (ret._month == 13)
	//	{
	//		ret._year++;
	//		ret._month = 1;
	//	}
	//}
	ret += day;
	return ret;
}



// 日期-天数

Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}



// 日期-=天数

Date& Date::operator-=(int day)
{
	if (day<0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day<=0)
	{
		_month--;
		if (_month==0)
		{
			_month = 12;
			_year--;
		}
		//月份给的是前一个月，而不是原来的月份
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}


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

int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this<d)
	{
		min = *this;
		max = d;
		flag = -1;
	}
	//让小的累加至大的
	//累加的天数n为差值
	int n = 0;
	while (min != max)
	{
		n++;
		min++;
	}

	return n*flag;
}

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

