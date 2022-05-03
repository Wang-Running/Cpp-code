#define _CRT_SECURE_NO_WARNINGS
#pragma once
namespace A
{
	int b = 0;
	namespace cache
	{
		struct Node
		{
			int val;
			struct Node* next;
		};
	}
}


//嵌套使用
//同名的命名空间会被合并
//b还是全局变量，命名空间不影响生命周期
