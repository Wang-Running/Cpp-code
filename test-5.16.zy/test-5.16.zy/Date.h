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

	// ��ȡĳ��ĳ�µ�����
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

	// ȫȱʡ�Ĺ��캯��

	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year < 1900 ||

			month < 1 || month > 12 ||

			day < 1 || day > GetMonthDay(year, month))

		{
			cout << "�Ƿ�����" << endl;
		}

	}



	//// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;

		_month = d._month;

		_day = d._day;
	}



	// ��ֵ���������

	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);



	// ��������
	~Date();



	// ����+=����
	Date& operator+=(int day);



	// ����+����
	Date operator+(int day);



	// ����-����
	Date operator-(int day);



	// ����-=����
	Date& operator-=(int day);



	// ǰ��++
	Date& operator++();



	// ����++
	Date operator++(int);



	// ����--
	Date operator--(int);



	// ǰ��--
	Date& operator--();

	// >���������
	bool operator>(const Date& d);



	// ==���������
	bool operator==(const Date& d);



	// >=���������
	inline bool operator >= (const Date& d);



	// <���������
	bool operator < (const Date& d);



	// <=���������
	bool operator <= (const Date& d);



	// !=���������
	bool operator != (const Date& d);


	// ����-���� ��������
	int operator-(const Date& d);

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