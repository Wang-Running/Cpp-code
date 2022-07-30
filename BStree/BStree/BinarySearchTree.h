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
private:
	//������
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

	//���ƽ�㹹����
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
	//ǿ��Ĭ�Ϲ���
	BSTree() = default;
	//��������
	BSTree(const BSTree<k>& t)		//д�˿������죬�Ͳ���Ĭ�����ɹ��캯��
	{
		_root = CopyTree(t._root);
	}

	//��ֵ���ִ�д��
	BSTree<k>& operator=(BSTree<k> t)
	{
		swap(_root, t._root);
		return *this;
	}

	//����
	~BSTree()
	{
		DestoryTree(_root);
		_root = nullptr;
	}

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
		Node* parent = _root;
		Node* cur = _root;
		//�Ȳ���
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
			else  //�ҵ���
			{
				//һ������--��/��Ϊ��
				//��������---�滻
				if (cur->_left==nullptr)
				{
					//�жϸ��׵�������ָ����
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
				else  //�����Ӷ���Ϊ��
				{
					//��������С��㣨��������㣩
					//��Ҫ�ҵ��丸�ף��滻��ɾminright�������������ܲ�Ϊ�գ�Ҫ���Ӹ��׽��
					Node* minParent = cur;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minParent = minRight;
						minRight = minRight->_left;
					}
					//ֵ����ɾ���ڵ��ֵ
					//cur->_key = minRight->_key;
					swap(minRight->_key, cur->_key);
					//���Ӹ��׽���ɾ���ڵ���Һ���
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
		//û�ҵ�
		return false;
	}


	//�������
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	///////////////////////////////////////////////////////////////////////////////////
	//���ҵݹ�
	bool FindR(const k& key)
	{
		return _FindR(_root, key);
	}
	//�ݹ����
	bool InsertR(const k& key)
	{
		return _InsertR(_root, key);
	}

	//�ݹ�ɾ��
	bool EraseR(const k& key)
	{
		return _EraseR(_root,key);
	}

private:

	//�ݹ�ɾ��
	bool _EraseR(Node*& root, const k& key)
	{
		//���ڿ����Ҳ���
		if (root == nullptr)
		{
			return false;
		}
		if (key > root->_key)
			return _EraseR(root->_right, key);
		else if (key < root->_key)
			return _EraseR(root->_left, key);
		else   //���--��ʼɾ��
		{
			//����Ҫɾ���Ĵ��룬����ɾ��
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

				//�ݹ�ɾ�����Ѿ�������ֵ����������ɾ������һ��Ϊ��
				return _EraseR(root->_right, key);
			}
			delete del;
			return true;
		}
	}

	//�ݹ����--֮ǰ�Ǳ������ڵ㣬cur�ҵ�λ�ú󣬴�������븸�������
	//����ֱ���ø��ڵ���������εݹ���ܽ������
	bool _InsertR(Node*& root, const k& key)
	{
		//���ڿյ�ʱ�����
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

	//���ҵݹ�
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

	//��������
	//BSTree<int> copy = t;
	//copy.InOrder();

	t.EraseR(14);
	t.InOrder();

}