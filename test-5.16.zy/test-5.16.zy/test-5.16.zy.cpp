#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

int main()
{
	Date d1(2008,10,1);
	Date d2(2008,11,2);
	d1 = d2;
	d1.Print();
	Date d3 = d1 + 20;
	d3.Print();
	return 0;
}