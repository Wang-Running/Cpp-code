#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"

// ��ֵ���������

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



//// ��������
//
//~Date()




//// ����+=����

//Date& operator+=(int day);



// ����+����

Date Date::operator+(int day)
{
	Date ret(*this);
	ret._day += day;
	//this->_day += day;
	return ret;
}



//// ����-����

//Date operator-(int day);



//// ����-=����

//Date& operator-=(int day);



//// ǰ��++

//Date& operator++();



//// ����++

//Date operator++(int);



//// ����--

//Date operator--(int);



//// ǰ��--

//Date& operator--();

// >���������

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


// ==���������

//�����������������:������Ƚϣ���ô���������β�
//����ֵ���������Ľṹ���Ƚ���ȷ�����ټ��ɣ���bool

//������������Ϊthisָ��
bool Date::operator==(const Date& d)
{
	return _year == d._year&&
		_month == d._month&&
		_day == d._day;
}



// >=���������

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



// <���������

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



// <=���������

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



// !=���������

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



// ����-���� ��������

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