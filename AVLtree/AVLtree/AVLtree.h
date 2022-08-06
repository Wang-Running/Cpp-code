#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template<class k,class v>

//������ ---���������漰����������
struct AVLTreeNode
{
	pair<k, v> _kv;
	AVLTreeNode<k, v>* _left;
	AVLTreeNode<k, v>* _right;
	AVLTreeNode<k, v>* _parent;
	
	int _bf;     //ƽ������--������-�������ĸ߶Ȳ�

	AVLTreeNode(const pair<k, v>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_bf(0)
	{}
};

template<class k, class v>
class AVLTree
{
	typedef AVLTreeNode<k, v> Node;
public:

	//����
	bool Insert(const pair<k,v>& kv)
	{
		//1. �����������Ĺ������
		//2. ���Ƿ�Υ��ƽ�����Υ������ת

		//����ʱ
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		//�ҵ�����λ��
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;  //ע����ĸ���

		// �Ѿ����������ˣ������ж�ƽ������--��Ӱ����һ��������ֻ��Ӱ�����ȣ������ڸ����ң�++����������--��
		//�����߶ȱ��˼������ϸ��£��߶Ȳ���ֹͣ����
		//û��Υ�����򣬽�����Υ������--��ת����

		while (parent) //��Զ���µ���
		{
			if (cur==parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}
			//�Ƿ������
			if (parent->_bf == 0)
			{
				break;  //�߶Ȳ���
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//�����߶ȱ��ˣ�������������
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//������ƽ����ת

			}
			else
			{
				//����֮ǰAVL�Ͳ�ƽ����
				assert(false);
			}
		}

		return true;

	}

private:
	Node* _root = nullptr;
};

void test1()
{
	AVLTree<int, int> av;
	av.Insert(make_pair(1,3));
	av.Insert(make_pair(2, 4));
	av.Insert(make_pair(6, 8));
	av.Insert(make_pair(7, 9));
	av.Insert(make_pair(8, 10));
}