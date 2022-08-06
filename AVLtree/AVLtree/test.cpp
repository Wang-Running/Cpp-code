#define _CRT_SECURE_NO_WARNINGS



//void RotateR(Node* parent)
//{
//	Node* subleft = parent->left;
//	Node* subright = parent->right;
//	Node* pprent = parent->parent;
//
//	if (subrighr)
//		parent->left = subright;
//	subright->parent = 
//
//}
//
//void RotateR(Node* parent)
//{
//	Node* subL = parent->left;
//	Node* subLR = subL->right;
//
//	parent->left = subLR;
//	if (subLR)
//		subLR->_parent = parent;
//
//	Node* ppNode = parent->parent;
//	subL->right = parent;
//	parent->_parent = subL;
//
//	if (parent == _root)
//	{
//		subL->_parent = nullptr;
//		_root = subL;
//	}
//	else
//	{
//		subL->_parent = ppNode;
//		if (ppNode->right == parent)
//		{
//			ppNode->right = subL;
//		}
//		else
//		{
//			ppNode->left = subL;
//		}
//	}
//	parent->_bf = subL->_bf = 0;
//}

#include "AVLtree.h"

int main()
{
	test1();
	return 0;
}