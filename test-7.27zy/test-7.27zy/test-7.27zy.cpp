#define _CRT_SECURE_NO_WARNINGS

//606. 根据二叉树创建字符串
//class Solution {
//public:
//	string tree2str(TreeNode* root) {
//
//		//左右都为空，需要省略括号
//		//右为空，需要省略括号
//		//左为空，右不为空，左不能省略()
//
//		if (root == nullptr)
//		{
//			return "";
//		}
//		string str;
//		str += to_string(root->val);
//
//		//递归左
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
//		//递归右
//		if (root->right)
//		{
//			str += "(";
//			str += tree2str(root->right);
//			str += ")";
//		}
//		return str;
//	}
//};


//102. 二叉树的层序遍历
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
//			//leveSize控制一层一层出
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
//			// 上一层出完，下一层都进队列
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
//		//存储每层结点
//		queue<TreeNode*> po;
//		//存每层结点个数
//		int levesize = 1;
//		//入栈
//		po.push(root);
//
//		//每层遍历，每层不为空，继续
//		while (!po.empty())
//		{
//			//新的数组存储--每层数据
//			vector<int> levenum;
//			//一层遍历--将每层的结点放入新数组中，然后入栈左右节点，再出栈，且重新统计遍历次数
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


//107. 二叉树的层序遍历 II
//class Solution {
//public:
//	vector<vector<int>> levelOrderBottom(TreeNode* root) {
//		vector<vector<int>> vv;
//		if (root == nullptr)
//			return vv;
//
//		//存储每层结点
//		queue<TreeNode*> po;
//		//存每层结点个数
//		int levesize = 1;
//		//入栈
//		po.push(root);
//
//		//每层遍历，每层不为空，继续
//		while (!po.empty())
//		{
//			//新的数组存储--每层数据
//			vector<int> levenum;
//			//一层遍历--将每层的结点放入新数组中，然后入栈左右节点，再出栈，且重新统计遍历次数
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

//236. 二叉树的最近公共祖先
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
//		//p在左边
//		bool pInleft = IsSubTree(root->left, p);
//		//p在右边
//		bool pInright = !pInleft;
//
//		//q在左边
//		bool qInleft = IsSubTree(root->left, q);
//		//q在右边
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

//JZ36 二叉搜索树与双向链表
//class Solution {
//public:
//	//中序遍历，更改连接关系
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