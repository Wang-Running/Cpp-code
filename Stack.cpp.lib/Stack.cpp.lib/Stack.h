#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int Datatype;

typedef struct Stack
{
	Datatype* a;
	int top;   //栈顶位置
	int capacity;   //容量
}ST;

#ifdef __cplusplus
	#define C extern "C"
#else
	#define C
#endif

C void StackInit(ST* ps);

C void StackDestory(ST* ps);

C void StackPush(ST* ps, Datatype x);

C void StackPop(ST* ps);

	//判断栈是否为空
C bool StackEmpty(ST* ps);

	//数据个数
C int StackSize(ST* ps);

	//访问栈顶数据
C Datatype StackTop(ST* ps);
