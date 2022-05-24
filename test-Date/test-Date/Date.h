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
		_year = year;

		_month = month;

		_day = day;
	}



	//// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		cout << "���쿽��" << endl;
		_year = d._year;

		_month = d._month;

		_day = d._day;
	}



	// ��ֵ���������

	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);




	// ��������
	~Date()
	{

	}



	// ����+=����
	Date& operator+=(int day);



	// ����+����
	Date operator+(int day);



	// ����-����
	Date operator-(int day);



	// ����-=����
	Date& operator-=(int day);



	// ǰ��++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date ret(*this);
		ret += 1;
		return ret;
	}



	// ����--
	Date operator--(int)
	{
		Date ret(*this);
		ret -= 1;
		return ret;
	}

	// ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >���������
	bool operator>(const Date& d) const;



	// ==���������
	bool operator==(const Date& d) const;



	// >=���������
	inline bool operator >= (const Date& d) const;



	// <���������
	bool operator < (const Date& d) const;



	// <=���������
	bool operator <= (const Date& d) const;



	// !=���������
	bool operator != (const Date& d) const;


	// ����-���� ��������
	int operator-(const Date& d);

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//д�ں�������
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


