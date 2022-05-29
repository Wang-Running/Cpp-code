#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
using namespace std;

//new��delete
//int main()
//{
//	//newһ������
//	int* p1 = new int(5);
//	delete p1;
//
//	//new�������
//	int* p2 = new int[10];
//	int* p3 = new int[10]{1, 2, 3, 4, 5, 6};
//	delete[] p2;
//	delete[] p3;
//}

//C��˵
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
//	//Ϊ�˴����½�㣬����Ҫͨ��Buynode����
//	struct Listnode* L1 = Buynode(1);
//	
//}

//C++����
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
//		//��¼�ڵ���
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
//		//ÿһ�β������ݣ�����Ҫnewһ���ڵ�
//		Listnode* newnode = new Listnode;
//		Listnode* tail = _head->_prev;
//
//		//����
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