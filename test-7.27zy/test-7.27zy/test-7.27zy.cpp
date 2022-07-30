#define _CRT_SECURE_NO_WARNINGS

//606. ���ݶ����������ַ���
//class Solution {
//public:
//	string tree2str(TreeNode* root) {
//
//		//���Ҷ�Ϊ�գ���Ҫʡ������
//		//��Ϊ�գ���Ҫʡ������
//		//��Ϊ�գ��Ҳ�Ϊ�գ�����ʡ��()
//
//		if (root == nullptr)
//		{
//			return "";
//		}
//		string str;
//		str += to_string(root->val);
//
//		//�ݹ���
//		if (root->left)
//		{
//			str += "(";
//			str += tree2str(root->left);
//			str += ")";
//		}
//		else if (root->right)
//		{
//			str += "()";
//		}
//
//		//�ݹ���
//		if (root->right)
//		{
//			str += "(";
//			str += tree2str(root->right);
//			str += ")";
//		}
//		return str;
//	}
//};


//102. �������Ĳ������
//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		vector<vector<int>> vv;
//		if (root == nullptr)
//			return vv;
//
//
//		queue<TreeNode*> q;
//		int leveSize = 1;
//		q.push(root);
//
//
//		while (!q.empty())
//		{
//			//leveSize����һ��һ���
//			vector<int> levelv;
//			while (leveSize--)
//			{
//				TreeNode* front = q.front();
//				q.pop();
//				levelv.push_back(front->val);
//				if (front->left)
//					q.push(front->left);
//				if (front->right)
//					q.push(front->right);
//			}
//			vv.push_back(levelv);
//			// ��һ����꣬��һ�㶼������
//			leveSize = q.size();
//		}
//
//
//		return vv;
//	}
//};
//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		vector<vector<int>> vv;
//		if (root == nullptr)
//			return vv;
//
//		//�洢ÿ����
//		queue<TreeNode*> po;
//		//��ÿ�������
//		int levesize = 1;
//		//��ջ
//		po.push(root);
//
//		//ÿ�������ÿ�㲻Ϊ�գ�����
//		while (!po.empty())
//		{
//			//�µ�����洢--ÿ������
//			vector<int> levenum;
//			//һ�����--��ÿ��Ľ������������У�Ȼ����ջ���ҽڵ㣬�ٳ�ջ��������ͳ�Ʊ�������
//			while (levesize--)
//			{
//				levenum.push_back(po.front()->val);
//				if (po.front()->left)
//					po.push(po.front()->left);
//				if (po.front()->right)
//					po.push(po.front()->right);
//				po.pop();
//			}
//			vv.push_back(levenum);
//			levesize = po.size();
//		}
//		return vv;
//	}
//};


//107. �������Ĳ������ II
//class Solution {
//public:
//	vector<vector<int>> levelOrderBottom(TreeNode* root) {
//		vector<vector<int>> vv;
//		if (root == nullptr)
//			return vv;
//
//		//�洢ÿ����
//		queue<TreeNode*> po;
//		//��ÿ�������
//		int levesize = 1;
//		//��ջ
//		po.push(root);
//
//		//ÿ�������ÿ�㲻Ϊ�գ�����
//		while (!po.empty())
//		{
//			//�µ�����洢--ÿ������
//			vector<int> levenum;
//			//һ�����--��ÿ��Ľ������������У�Ȼ����ջ���ҽڵ㣬�ٳ�ջ��������ͳ�Ʊ�������
//			while (levesize--)
//			{
//				levenum.push_back(po.front()->val);
//				if (po.front()->left)
//					po.push(po.front()->left);
//				if (po.front()->right)
//					po.push(po.front()->right);
//				po.pop();
//			}
//			vv.push_back(levenum);
//			levesize = po.size();
//		}
//		reverse(vv.begin(), vv.end());
//		return vv;
//	}
//};

//236. �������������������
//class Solution {
//public:
//
//	bool IsSubTree(TreeNode* tree, TreeNode* x)
//	{
//		if (tree == nullptr)
//			return false;
//		if (tree == x)
//			return true;
//
//		return IsSubTree(tree->left, x)
//			|| IsSubTree(tree->right, x);
//	}
//
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		if (root == nullptr)
//			return nullptr;
//
//		if (root == p || root == q)
//			return root;
//
//		//p�����
//		bool pInleft = IsSubTree(root->left, p);
//		//p���ұ�
//		bool pInright = !pInleft;
//
//		//q�����
//		bool qInleft = IsSubTree(root->left, q);
//		//q���ұ�
//		bool qInright = !qInleft;
//
//		if ((pInleft && qInright) || (pInright && qInleft))
//			return root;
//		else if (pInleft && qInleft)
//			return lowestCommonAncestor(root->left, p, q);
//		else if (pInright && qInright)
//			return lowestCommonAncestor(root->right, p, q);
//		else
//			return nullptr;
//
//	}
//};

//JZ36 ������������˫������
//class Solution {
//public:
//	//����������������ӹ�ϵ
//	void CreatTree(TreeNode* cur, TreeNode*& prev)
//	{
//		if (cur == nullptr)
//		{
//			return;
//		}
//		CreatTree(cur->left, prev);
//		cur->left = prev;
//		if (prev)
//			prev->right = cur;
//		prev = cur;
//
//		CreatTree(cur->right, prev);
//	}
//
//
//	TreeNode* Convert(TreeNode* pRootOfTree) {
//		if (pRootOfTree == nullptr)
//		{
//			return nullptr;
//		}
//		TreeNode* prev = nullptr;
//		CreatTree(pRootOfTree, prev);
//
//		TreeNode* head = pRootOfTree;
//		while (head->left)
//			head = head->left;
//		return head;
//	}
//};