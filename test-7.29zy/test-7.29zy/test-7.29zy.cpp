#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

//105. 从前序与中序遍历序列构造二叉树
//class Solution {
//public:
//	//前序下标，中序区间
//	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend) {
//		//区间不存在，空树
//		if (inbegin > inend)
//			return nullptr;
//		//前序确定根节点
//		TreeNode* root = new TreeNode(preorder[prei]);
//		prei++;
//		//中序确定区间
//		size_t rooti = inbegin;
//		while (rooti <= inend)
//		{
//			if (root->val == inorder[rooti])
//			{
//				break;
//			}
//			else
//			{
//				rooti++;
//			}
//
//			//[inbegin, rooti-1] rooti [rooti+1,inend]
//		}
//
//		//递归创建左右子树
//		root->left = _buildTree(preorder, inorder, prei, inbegin, rooti - 1);
//		root->right = _buildTree(preorder, inorder, prei, rooti + 1, inend);
//		return root;
//	}
//
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		int prei = 0, inbegin = 0, inend = inorder.size() - 1;
//		return _buildTree(preorder, inorder, prei, inbegin, inend);
//	}
//};


//106. 从中序与后序遍历序列构造二叉树
//struct TreeNode {
//   int val;
//    TreeNode *left;
//    TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
//
//
//TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& orderi, int inbegin, int inend) {
//	//区间不存在，空树
//	if (inbegin > inend)
//		return nullptr;
//	//后序确定根节点
//	TreeNode* root = new TreeNode(postorder[orderi]);
//	orderi--;
//	//中序确定区间
//	size_t rooti = inbegin;
//	while (rooti <= inend)
//	{
//		if (root->val == inorder[rooti])
//		{
//			break;
//		}
//		else
//		{
//			rooti++;
//		}
//		//[inbegin, rooti-1] rooti [rooti+1,inend]
//	}
//
//	//递归创建左右子树
//	root->right = _buildTree(inorder, postorder, orderi, rooti + 1, inend);
//	root->left = _buildTree(inorder, postorder, orderi, inbegin, rooti - 1);
//	return root;
//
//}
//
//TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
//{
//	int orderi = postorder.size() - 1, inbegin = 0, inend = inorder.size() - 1;
//	return _buildTree(inorder, postorder, orderi, inbegin, inend);
//}
//
//int main()
//{
//	vector<int> inorder;
//	vector<int> postorder;
//	inorder.push_back(9);
//	inorder.push_back(3);
//	inorder.push_back(15);
//	inorder.push_back(20);
//	inorder.push_back(7);
//
//	postorder.push_back(9);
//	postorder.push_back(15);
//	postorder.push_back(7);
//	postorder.push_back(20);
//	postorder.push_back(3);
//
//	buildTree(inorder,postorder);
//
//	return 0;
//}
	

//144. 二叉树的前序遍历
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		vector<int> v;
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		while (cur || !st.empty())
//		{
//			//先将左路结点全部入栈
//			while (cur)
//			{
//				v.push_back(cur->val);
//				st.push(cur);
//				cur = cur->left;
//			}
//
//			//保留出栈的左路结点
//			TreeNode* top = st.top();
//			st.pop();
//
//
//			//访问左路结点右子树
//			cur = top->right;
//		}
//
//
//		return v;
//	}
//};


//94. 二叉树的中序遍历
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		vector<int> v;
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		while (cur || !st.empty())
//		{
//			//先将左路结点全部入栈
//			while (cur)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//
//			//保留出栈的左路结点--入队列
//			TreeNode* top = st.top();
//			st.pop();
//			v.push_back(top->val);
//
//			//访问左路结点右子树
//			cur = top->right;
//		}
//		return v;
//	}
//};

//145. 二叉树的后序遍历
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		vector<int> v;
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		TreeNode* prev = nullptr;   //记录前一个访问出栈的结点，方便判断此节点要不要访问并出栈
//		while (cur || !st.empty())
//		{
//			//先将左路结点全部入栈
//			while (cur)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//
//			TreeNode* top = st.top();
//			if (top->right == nullptr || top->right == prev)
//			{
//				v.push_back(top->val);
//				st.pop();
//				prev = top;
//			}
//			else   //访问右子树，入栈右子树的左结点
//			{
//				cur = top->right;
//			}
//		}
//		return v;
//	}
//};