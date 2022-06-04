#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
using namespace std;

//先把一年内每月间的差值求出
int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

//判断闰年
bool leapyear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return true;
	}
	else
		return false;
}

//确定年有多少天
int yeardays(int year)
{
	if (leapyear(year))
	{
		return 366;
	}
	else
		return 365;
}

int sum(int year, int month, int day)
{
	int sum = 0;
	//从元年开始算
	for (int i = 0; i<year; i++)
	{
		sum += yeardays(i);
	}
	if (leapyear(year))
	{
		sum += days[month - 1] + day+1;
	}
	else
	{
		sum += days[month - 1] + day;
	}
	return sum;
}

int main()
{
	int year1, month1, day1;
	int year2, month2, day2;
	while (~scanf("%04d%02d%02d", &year1, &month1, &day1))
	{
		scanf("%04d%02d%02d", &year2, &month2, &day2);
		printf("%d\n", abs(sum(year1, month1, day1) -
			sum(year2, month2, day2)) + 1);
	}
	return 0;
}