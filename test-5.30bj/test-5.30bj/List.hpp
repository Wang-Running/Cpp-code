#define _CRT_SECURE_NO_WARNINGS
#pragma once

//ÉùÃ÷
template <class T>
class List
{
public:
	List(size_t capacity = 10);
private:
	T* _Data;
	size_t _size;
	size_t _capacity;
};

