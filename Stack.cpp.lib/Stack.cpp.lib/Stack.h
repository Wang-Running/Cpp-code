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

#ifdef __cplusplus
	#define C extern "C"
#else
	#define C
#endif

C void StackInit(ST* ps);

C void StackDestory(ST* ps);

C void StackPush(ST* ps, Datatype x);

C void StackPop(ST* ps);

	//�ж�ջ�Ƿ�Ϊ��
C bool StackEmpty(ST* ps);

	//���ݸ���
C int StackSize(ST* ps);

	//����ջ������
C Datatype StackTop(ST* ps);
