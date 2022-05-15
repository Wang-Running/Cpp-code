#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <cassert>
#include <iostream>
using namespace std;
class Stack
{
public:
	void Init();
	void Push(int x);

	int Top();
private:
	int* _a;
	int _top;
	int _capacity;
};