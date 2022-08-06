#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template<class k,class v>

//定义结点 ---三叉链，涉及到回溯问题
struct AVLTreeNode
{
	pair<k, v> _kv;
	AVLTreeNode<k, v>* _left;
	AVLTreeNode<k, v>* _right;
	AVLTreeNode<k, v>* _parent;
	
	int _bf;     //平衡因子--右子树-左子树的高度差

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

	//插入
	bool Insert(const pair<k,v>& kv)
	{
		//1. 按照搜索树的规则插入
		//2. 看是否违反平衡规则，违反则旋转

		//空树时
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		//找到插入位置
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

		cur->_parent = parent;  //注意结点的更新

		// 已经将结点插入了，现在判断平衡因子--不影响另一颗子树，只会影响祖先（新增在父亲右，++，新增在左--）
		//子树高度变了继续往上更新，高度不变停止更新
		//没有违反规则，结束，违反规则--旋转处理

		while (parent) //最远更新到根
		{
			if (cur==parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}
			//是否继续更
			if (parent->_bf == 0)
			{
				break;  //高度不变
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//子树高度变了，继续更新祖先
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//子树不平衡旋转

			}
			else
			{
				//插入之前AVL就不平衡了
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