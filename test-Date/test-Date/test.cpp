#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

int main()
{
	Date d4(2008, 11, 28);
	d4.Print();
	d4 -= -1;
	d4.Print();
	return 0;
}