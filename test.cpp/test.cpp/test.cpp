#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//���߱�������entern"C"��������C�⣬Ҫ��c�ķ�ʽȥ����
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