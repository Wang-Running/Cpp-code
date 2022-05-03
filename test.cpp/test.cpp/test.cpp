#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//告诉编译器，entern"C"声明的是C库，要用c的方式去链接
extern "C"
{
#include "../../Stack_C.lib/Stack_C.lib/Stack.h"
}


int main()
{
	ST* B = (ST*)malloc(sizeof(ST));
	StackInit(B);
	StackDestory(B);
	return 0;
}