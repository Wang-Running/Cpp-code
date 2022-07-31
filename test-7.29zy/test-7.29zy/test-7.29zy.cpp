#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;


struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& orderi, int inbegin, int inend) {
	//区间不存在，空树
	if (inbegin > inend)
		return nullptr;
	//后序确定根节点
	TreeNode* root = new TreeNode(postorder[orderi]);
	orderi--;
	//中序确定区间
	size_t rooti = inbegin;
	while (rooti <= inend)
	{
		if (root->val == inorder[rooti])
		{
			break;
		}
		else
		{
			rooti++;
		}
		//[inbegin, rooti-1] rooti [rooti+1,inend]
	}

	//递归创建左右子树
	root->right = _buildTree(inorder, postorder, orderi, rooti + 1, inend);
	root->left = _buildTree(inorder, postorder, orderi, inbegin, rooti - 1);
	return root;

}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	int orderi = postorder.size() - 1, inbegin = 0, inend = inorder.size() - 1;
	return _buildTree(inorder, postorder, orderi, inbegin, inend);
}

int main()
{
	vector<int> inorder;
	vector<int> postorder;
	inorder.push_back(9);
	inorder.push_back(3);
	inorder.push_back(15);
	inorder.push_back(20);
	inorder.push_back(7);

	postorder.push_back(9);
	postorder.push_back(15);
	postorder.push_back(7);
	postorder.push_back(20);
	postorder.push_back(3);

	buildTree(inorder,postorder);

	return 0;
}
	
