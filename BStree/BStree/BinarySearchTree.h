#define _CRT_SECURE_NO_WARNINGS

#pragma once
//struct BinarySerchTreeNode

//���
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
		//����ʱ
		if (_root==nullptr)
		{
			_root = new Node(key);
			return true;
		}

		//�տ�ʼ���׾͵��ڸ��ڵ�
		//cur--ȷ��������λ��
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
				//��Ȳ��ܲ���
				return false;
			}
		}
		//�ҵ�λ�ú󣬴�����㣬��������
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

	//����
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

	//ɾ��
	bool Erase(const k& key)
	{

	}


	//�������
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