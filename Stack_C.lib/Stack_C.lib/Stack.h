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
	int top;   //ջ��λ��
	int capacity;   //����
}ST;

void StackInit(ST* ps);

void StackDestory(ST* ps);

void StackPush(ST* ps,Datatype x);

void StackPop(ST* ps);

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);

//���ݸ���
int StackSize(ST* ps);

//����ջ������
Datatype StackTop(ST* ps);