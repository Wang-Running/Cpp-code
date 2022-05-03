#define _CRT_SECURE_NO_WARNINGS
#pragma once

namespace A
{
	int a = 0;
	namespace data
	{
		struct Node
		{
			int val;
			struct Node* next;
		};
	}
}