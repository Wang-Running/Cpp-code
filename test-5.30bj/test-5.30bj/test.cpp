#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.hpp"
using namespace std;


template <class T1>
T1 Add(const T1& x, const T1& y)
{
	return x + y;
}

int Add(int x,int y)
{
	return x + y;
}

int main()
{
	Add(1,2);
	Add<int>(1,2);
	return 0;
}


//int main()
//{
//	List<int>L1;
//	List<char>L2;
//	List<double>L3;
//	return 0;
//}