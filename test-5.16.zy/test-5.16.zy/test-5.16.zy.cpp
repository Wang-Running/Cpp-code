#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Date
{
public:

	// 获取某年某月的天数
	bool Leapyear(int year)
	{
		if ((year/4==0&&year/100!=0)||(year/400==0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetMonthDay(int year, int month)
	{
		int MDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month==2 && Leapyear(year))
		{
			return MDay[month]+1;
		}
		else
		{
			return MDay[month];
		}
	}

	// 全缺省的构造函数

	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year < 1900 ||

			month < 1 || month > 12 ||

			day < 1 || day > GetMonthDay(year, month))

		{
			cout << "非法日期" << endl;
		}

	}



	//// 拷贝构造函数

	// d2(d1)

	Date(const Date& d)
	{
		_year = d._year;

		_month = d._month;

		_day = d._day;
	}



	// 赋值运算符重载

	// d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
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

	//~Date();



	//// 日期+=天数

	//Date& operator+=(int day);



	// 日期+天数

	Date operator+(int day)
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

	bool operator>(const Date& d)
	{
		if ((_year > d._year) ||
			(_year == d._year) && (_month > d._month) ||
			(_year == d._year) && (_month == d._month) && (_day > d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	// ==运算符重载

	bool operator==(const Date& d)
	{
		return _year == d._year&&
		_month == d._month&&
		_day == d._day;
	}



	// >=运算符重载

	inline bool operator >= (const Date& d)
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
	}



	// <运算符重载

	bool operator < (const Date& d)
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

	bool operator <= (const Date& d)
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

	bool operator != (const Date& d)
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

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	d1.SetDate(2018, 9, 80);
	d1.Print();
	Date d2;
	d2.SetDate(2018, 9, 1);
	d2 + 5;
	d2.Print();
	Date d3;
	d3 = (d2 + 5);
	d3.Print();
	//if (d1 == d2)
	//{
	//	cout << "==" << endl;
	//}
	//if (d1 < d2)
	//{
	//	cout << "<" << endl;
	//}
	//if (d1 > d2)
	//{
	//	cout << ">" << endl;
	//}
	//if (d1 <= d2)
	//{
	//	cout << "<=" << endl;
	//}
	//if (d1 >= d2)
	//{
	//	cout << ">=" << endl;
	//}
	//if (d1 != d2)
	//{
	//	cout << "!=" << endl;
	//}


	return 0;
}