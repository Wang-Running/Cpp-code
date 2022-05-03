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

void StackInit(ST* ps);

void StackDestory(ST* ps);

void StackPush(ST* ps,Datatype x);

void StackPop(ST* ps);

//判断栈是否为空
bool StackEmpty(ST* ps);

//数据个数
int StackSize(ST* ps);

//访问栈顶数据
Datatype StackTop(ST* ps);