#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//#include <cmath>
//using namespace std;
//
////先把一年内每月间的差值求出
//int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//
////判断闰年
//bool leapyear(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
////确定年有多少天
//int yeardays(int year)
//{
//	if (leapyear(year))
//	{
//		return 366;
//	}
//	else
//		return 365;
//}
//
//int sum(int year, int month, int day)
//{
//	int sum = 0;
//	//从元年开始算
//	for (int i = 0; i<year; i++)
//	{
//		sum += yeardays(i);
//	}
//	if (leapyear(year))
//	{
//		sum += days[month - 1] + day+1;
//	}
//	else
//	{
//		sum += days[month - 1] + day;
//	}
//	return sum;
//}
//
//int main()
//{
//	int year1, month1, day1;
//	int year2, month2, day2;
//	while (~scanf("%04d%02d%02d", &year1, &month1, &day1))
//	{
//		scanf("%04d%02d%02d", &year2, &month2, &day2);
//		printf("%d\n", abs(sum(year1, month1, day1) -
//			sum(year2, month2, day2)) + 1);
//	}
//	return 0;
//}

//KY222 打印日期 
//#include <iostream>
//using namespace std;
//
//bool leapyear(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
//void time(int year, int day, int days1[], int days2[])
//{
//	if (leapyear(year))
//	{
//		int i = 1;
//		while (i<13)
//		{
//			int d;
//			if (day > days2[i] && day <= days2[i + 1])
//			{
//				d = (day - days2[i]);
//				printf("%04d-%02d-%02d\n", year, i + 1, d);
//				break;
//			}
//			if (day <= days2[i])
//			{
//				d = day - days2[i - 1];
//				printf("%04d-%02d-%02d\n", year, i, d);
//				break;
//			}
//			i++;
//		}
//	}
//	else
//	{
//		int i = 1;
//		while (i<13)
//		{
//			int d;
//			if (day > days1[i] && day <= days1[i + 1])
//			{
//				d = (day - days1[i]);
//				printf("%04d-%02d-%02d\n", year, i + 1, d);
//				break;
//			}
//			if (day == days1[i])
//			{
//				d = day - days1[i - 1];
//				printf("%04d-%02d-%02d\n", year, i, d);
//				break;
//			}
//			i++;
//		}
//	}
//}
//
//int main()
//{
//	int days1[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	int days2[13] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
//	int year = 2000, day = 55;
//	while (~scanf("%d %d", &year, &day))
//	{
//		time(year, day, days1, days2);;
//	}
//	return 0;
//}


//KY258 日期累加
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool leapyear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void time(int year, int month, int day, int days, int days1[], int days2[])
{
	if (leapyear)
	{
		//1.不跨年
		while (month < 12 && (day + days) > days2[month])
		{
			days -= days2[month];
			month++;
		}
		if (month < 12 && (day + days) <= days2[month])
		{
			day += days;
			printf("%4d-%02d-%02d\n", year, month, day);
		}

		//2.跨年，要注意也要判断平年还是闰年
		while (month == 12)
		{
			days -= days2[month];
			month = 1;
			year++;
			//判断年
			if (leapyear(year))
			{
				while (month<12 && (day + days) > days2[month])
				{
					days -= days2[month];
					month++;
				}
				if (month<12 && (day + days) <= days2[month])
				{
					day += days;
					printf("%4d-%02d-%02d\n", year, month, day);
				}
			}
			else
			{
				while (month<12 && (day + days) > days1[month])
				{
					days -= days1[month];
					month++;
				}
				if (month<12 && (day + days) <= days1[month])
				{
					day += days;
					printf("%4d-%02d-%02d\n", year, month, day);
				}
			}
		}
	}
	else
	{
		//1.不跨年
		while (month < 12 && (day + days) > days1[month])
		{
			days -= days1[month];
			month++;
		}
		if (month < 12 && (day + days) <= days1[month])
		{
			day += days;
			printf("%4d-%02d-%02d\n", year, month, day);
		}

		//2.跨年
		while (month == 12)
		{
			days -= days1[month];
			month = 1;
			year++;
			//判断年份
			if (!leapyear(year))
			{
				while (month<12 && (day + days) > days1[month])
				{
					days -= days1[month];
					month++;
				}
				if (month<12 && (day + days) <= days1[month])
				{
					day += days;
					printf("%4d-%02d-%02d\n", year, month, day);
				}
			}
			else
			{
				while (month<12 && (day + days) > days2[month])
				{
					days -= days2[month];
					month++;
				}
				if (month<12 && (day + days) <= days2[month])
				{
					day += days;
					printf("%4d-%02d-%02d\n", year, month, day);
				}
			}
		}
	}
}

int main()
{
	int days1[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days2[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int num, year, month, day, days;
	cin >> num;
	for (int i = 0; i<num; i++)
	{
		cin >> year >> month >> day >> days;
		time(year, month, day, days, days1, days2);
	}
	return 0;
}