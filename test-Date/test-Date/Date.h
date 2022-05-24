#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <cassert>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Date
{
public:

	// 获取某年某月的天数
	bool Leapyear(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetMonthDay(int year, int month);


	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year < 1900 ||

			month < 1 || month > 12 ||

			day < 1 || day > GetMonthDay(year, month))

		{
			cout << "非法日期" << endl;
		}
		_year = year;

		_month = month;

		_day = day;
	}



	//// 拷贝构造函数
	// d2(d1)
	Date(const Date& d)
	{
		cout << "构造拷贝" << endl;
		_year = d._year;

		_month = d._month;

		_day = d._day;
	}



	// 赋值运算符重载

	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);




	// 析构函数
	~Date()
	{

	}



	// 日期+=天数
	Date& operator+=(int day);



	// 日期+天数
	Date operator+(int day);



	// 日期-天数
	Date operator-(int day);



	// 日期-=天数
	Date& operator-=(int day);



	// 前置++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// 后置++
	Date operator++(int)
	{
		Date ret(*this);
		ret += 1;
		return ret;
	}



	// 后置--
	Date operator--(int)
	{
		Date ret(*this);
		ret -= 1;
		return ret;
	}

	// 前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >运算符重载
	bool operator>(const Date& d) const;



	// ==运算符重载
	bool operator==(const Date& d) const;



	// >=运算符重载
	inline bool operator >= (const Date& d) const;



	// <运算符重载
	bool operator < (const Date& d) const;



	// <=运算符重载
	bool operator <= (const Date& d) const;



	// !=运算符重载
	bool operator != (const Date& d) const;


	// 日期-日期 返回天数
	int operator-(const Date& d);

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//写在函数后面
	void Print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date* operator&()
	{
		return nullptr;
	}

	const Date* operator&() const
	{
		return nullptr;
	}

	//int Getyear() const
	//{
	//	return _year;
	//}
	//int Getmonth() const
	//{
	//	return _month;
	//}
	//int Getday() const
	//{
	//	return _day;
	//}
	friend std::ostream& operator<< (std::ostream& out, const Date& d);
	friend std::istream& operator>> (std::istream& in, Date& d);
private:
	int _year;
	int _month;
	int _day;
};


