#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

//初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//销毁
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, Datatype x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = realloc(ps->a, newcapacity*sizeof(Datatype));
		if (ps->a == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top>0);
	ps->top--;
}

//判断栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	//if (ps->top > 0)
	//{
	//	return false;
	//}
	//else
	//{
	//	return true;
	//}
	return ps->top == 0;
}

//数据个数
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

//访问栈顶数据
Datatype StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top>0);
	return ps->a[ps->top-1];
}