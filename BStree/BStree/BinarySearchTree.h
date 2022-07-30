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
private:
	//销毁树
	void DestoryTree(Node* root)
	{
		if (root==nullptr)
		{
			return;
		}
		DestoryTree(root->_left);
		DestoryTree(root->_right);
		delete root;
	}

	//复制结点构造树
	Node* CopyTree(Node* root)
	{
		if (root==nullptr)
		{
			return nullptr;
		}
		Node* copyNode = new Node(root->_key);
		copyNode->_left = CopyTree(root->_left);
		copyNode->_right = CopyTree(root->_right);

		return copyNode;
	}
public:
	//强制默认构造
	BSTree() = default;
	//拷贝构造
	BSTree(const BSTree<k>& t)		//写了拷贝构造，就不会默认生成构造函数
	{
		_root = CopyTree(t._root);
	}

	//赋值，现代写法
	BSTree<k>& operator=(BSTree<k> t)
	{
		swap(_root, t._root);
		return *this;
	}

	//析构
	~BSTree()
	{
		DestoryTree(_root);
		_root = nullptr;
	}

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
		Node* parent = _root;
		Node* cur = _root;
		//先查找
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
			else  //找到了
			{
				//一个孩子--左/右为空
				//两个孩子---替换
				if (cur->_left==nullptr)
				{
					//判断父亲的左还是右指向孩子
					if (cur==parent->_left)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}

					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == parent->_left)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}

					delete cur;
				}
				else  //两孩子都不为空
				{
					//找右树最小结点（左树最大结点）
					//还要找到其父亲，替换后删minright，其右子树可能不为空，要连接父亲结点
					Node* minParent = cur;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minParent = minRight;
						minRight = minRight->_left;
					}
					//值代替删除节点的值
					//cur->_key = minRight->_key;
					swap(minRight->_key, cur->_key);
					//连接父亲结点和删除节点的右孩子
					if (minParent->_left==minRight)
					{
						minParent->_left = minRight->_right;
					}
					else
					{
						minParent->_right = minRight->_right;
					}

					delete minRight;
				}

				return true;
			}
		}
		//没找到
		return false;
	}


	//中序遍历
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	///////////////////////////////////////////////////////////////////////////////////
	//查找递归
	bool FindR(const k& key)
	{
		return _FindR(_root, key);
	}
	//递归插入
	bool InsertR(const k& key)
	{
		return _InsertR(_root, key);
	}

	//递归删除
	bool EraseR(const k& key)
	{
		return _EraseR(_root,key);
	}

private:

	//递归删除
	bool _EraseR(Node*& root, const k& key)
	{
		//等于空则找不到
		if (root == nullptr)
		{
			return false;
		}
		if (key > root->_key)
			return _EraseR(root->_right, key);
		else if (key < root->_key)
			return _EraseR(root->_left, key);
		else   //相等--开始删除
		{
			//保存要删除的代码，方便删除
			Node* del = root;
			if (root->_left==nullptr)
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else
			{
				Node* minRight = root->_right;
				while (minRight->_left)
				{
					minRight = minRight->_left;
				}

				swap(root->_key, minRight->_key);

				//递归删除，已经互换了值，在子树中删除，左一定为空
				return _EraseR(root->_right, key);
			}
			delete del;
			return true;
		}
	}

	//递归插入--之前是保留父节点，cur找到位置后，创建结点与父结点连接
	//这里直接用根节点的引用依次递归就能解决问题
	bool _InsertR(Node*& root, const k& key)
	{
		//等于空的时候插入
		if (root==nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (key > root->_key)
			return _InsertR(root->_right, key);
		else if (key < root->_key)
			return _InsertR(root->_left, key);
		else
			return false;
	}

	//查找递归
	bool _FindR(Node* root, const k& key)
	{
		if (root == nullptr)
			return false;
		if (key > root->_key)
		{
			return _FindR(root->_right, key);
		}
		else if (key < root->_key)
		{
			return _FindR(root->_left, key);
		}
		else
		{
			return true;
		}
	}

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


void TestBSTree1()
{
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
	t.Erase(8);
	t.InOrder();
}

void TestBSTree2()
{
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();

	//拷贝构造
	//BSTree<int> copy = t;
	//copy.InOrder();

	t.EraseR(14);
	t.InOrder();

}