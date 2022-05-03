#define _CRT_SECURE_NO_WARNINGS

#include "../../Stack.cpp.lib/Stack.cpp.lib/Stack.h"


int main()
{
	ST* B = (ST*)malloc(sizeof(ST));
	StackInit(B);
	StackDestory(B);
	return 0;
}