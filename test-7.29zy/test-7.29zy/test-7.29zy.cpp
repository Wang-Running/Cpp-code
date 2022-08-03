#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

//105. ��ǰ��������������й��������
//class Solution {
//public:
//	//ǰ���±꣬��������
//	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend) {
//		//���䲻���ڣ�����
//		if (inbegin > inend)
//			return nullptr;
//		//ǰ��ȷ�����ڵ�
//		TreeNode* root = new TreeNode(preorder[prei]);
//		prei++;
//		//����ȷ������
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
//		//�ݹ鴴����������
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


//106. �����������������й��������
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
//	//���䲻���ڣ�����
//	if (inbegin > inend)
//		return nullptr;
//	//����ȷ�����ڵ�
//	TreeNode* root = new TreeNode(postorder[orderi]);
//	orderi--;
//	//����ȷ������
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
//	//�ݹ鴴����������
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
	

//144. ��������ǰ�����
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		vector<int> v;
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		while (cur || !st.empty())
//		{
//			//�Ƚ���·���ȫ����ջ
//			while (cur)
//			{
//				v.push_back(cur->val);
//				st.push(cur);
//				cur = cur->left;
//			}
//
//			//������ջ����·���
//			TreeNode* top = st.top();
//			st.pop();
//
//
//			//������·���������
//			cur = top->right;
//		}
//
//
//		return v;
//	}
//};


//94. ���������������
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		vector<int> v;
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		while (cur || !st.empty())
//		{
//			//�Ƚ���·���ȫ����ջ
//			while (cur)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//
//			//������ջ����·���--�����
//			TreeNode* top = st.top();
//			st.pop();
//			v.push_back(top->val);
//
//			//������·���������
//			cur = top->right;
//		}
//		return v;
//	}
//};

//145. �������ĺ������
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		vector<int> v;
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		TreeNode* prev = nullptr;   //��¼ǰһ�����ʳ�ջ�Ľ�㣬�����жϴ˽ڵ�Ҫ��Ҫ���ʲ���ջ
//		while (cur || !st.empty())
//		{
//			//�Ƚ���·���ȫ����ջ
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
//			else   //��������������ջ������������
//			{
//				cur = top->right;
//			}
//		}
//		return v;
//	}
//};