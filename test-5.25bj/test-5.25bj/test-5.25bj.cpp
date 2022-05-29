#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
using namespace std;

//new和delete
//int main()
//{
//	//new一个对象
//	int* p1 = new int(5);
//	delete p1;
//
//	//new多个对象
//	int* p2 = new int[10];
//	int* p3 = new int[10]{1, 2, 3, 4, 5, 6};
//	delete[] p2;
//	delete[] p3;
//}

//C来说
//struct Listnode
//{
//	int* next;
//	int val;
//};
//
//struct Listnode* Buynode(int x)
//{
//	struct Listnode* node = (struct Listnode*)malloc(sizeof(struct Listnode));
//	assert(node);
//	node->next = NULL;
//	node->val = x;
//	return node;
//};
//
//int main()
//{
//	//为了创造新结点，都需要通过Buynode函数
//	struct Listnode* L1 = Buynode(1);
//	
//}

//C++来讲
//class Listnode
//{
//public:
//	Listnode(int val = 3)
//		:_next(nullptr)
//		, _val(val)
//	{
//		cout << "Listnode(int val = 3)" << endl;
//	}
//
//	~Listnode()
//	{
//		_next = nullptr;
//		_val = 0;
//	}
//
//private:
//	int* _next;
//	int _val;
//};
//
//
//int main()
//{
//	Listnode* L2 = (Listnode*)operator new(sizeof(Listnode));
//
//
//	delete L2;
//}

//struct Listnode
//{
//	Listnode* _next;
//	Listnode* _prev;
//	int _data;
//	Listnode(int data = 0)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _data(data)
//	{
//		//记录节点数
//		cout << "Listnode" << endl;
//	}
//
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<Listnode>().allocate(1000);
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<Listnode>().deallocate((Listnode*)p, 1000);
//		cout << "memory pool deallocate" << endl;
//	}
//};
//
//class List
//{
//public:
//	List()
//	{
//		_head = new Listnode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//
//	void Push(int val)
//	{
//		//每一次插入数据，都需要new一个节点
//		Listnode* newnode = new Listnode;
//		Listnode* tail = _head->_prev;
//
//		//链接
//		tail->_next = newnode;
//		newnode->_prev = tail;
//		newnode->_next = _head;
//		_head->_prev = newnode;
//	}
//
//	~List()
//	{
//		Listnode* cur = _head->_next;
//		while (cur!=_head)
//		{
//			Listnode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//		delete _head;
//		_head = nullptr;
//	}
//
//private:
//	Listnode* _head;
//
//};
//
//
//int main()
//{
//	List l;
//	int n = 1000;
//	for (int i = 0;i<n;i++)
//	{
//		l.Push(i);
//	}
//}

class Listnode
{
public:
	Listnode(int val = 3)
		:_next(nullptr)
		, _val(val)
	{
		cout << "Listnode(int val = 3)" << endl;
	}

	~Listnode()
	{
		_next = nullptr;
		_val = 0;
	}

private:
	int* _next;
	int _val;
};


int main()
{
	Listnode* L2 = (Listnode*)operator new(sizeof(Listnode));
	new(L2)Listnode(6);
	delete L2;
}