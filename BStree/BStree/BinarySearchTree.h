#define _CRT_SECURE_NO_WARNINGS

#pragma once
//struct BinarySerchTreeNode

//结点
template <class k>
struct BSTreeNode
{
	BSTreeNode<k>* _left;
	BSTreeNode<k>* _right;

	k _key;
	BSTreeNode(const k& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template <class k>
class BSTree
{
	typedef BSTreeNode<k> Node;
public:
	bool Insert(const k& key)
	{
		//空树时
		if (_root==nullptr)
		{
			_root = new Node(key);
			return true;
		}

		//刚开始父亲就等于根节点
		//cur--确定插入结点位置
		Node* parent = _root;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//相等不能插入
				return false;
			}
		}
		//找到位置后，创建结点，进行连接
		cur = new Node(key);
		if (key > parent->_key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	//查找
	void Find(const k& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	//删除
	bool Erase(const k& key)
	{

	}


	//中序遍历
	void InOrder()
	{
		_InOrder(_root);
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	Node* _root=nullptr;
};

void TestBSTree()
{
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}