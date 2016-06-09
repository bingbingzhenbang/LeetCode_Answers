//Given a binary tree
//struct TreeLinkNode {
//	TreeLinkNode *left;
//	TreeLinkNode *right;
//	TreeLinkNode *next;
//}
//
//
//
//Populate each next pointer to point to its next right node.If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//You may only use constant extra space.
//You may assume that it is a perfect binary tree(ie, all leaves are at the same level, and every parent has two children).
//
//
//For example,
//Given the following perfect binary tree,
//
//1
/// \
//2    3
/// \ / \
//4  5  6  7
//
//
//
//After calling your function, the tree should look like :
//
//1->NULL
/// \
//2 -> 3->NULL
/// \ / \
//4->5->6->7->NULL

#include "TreeLinkNode.h"

using namespace std;

void InnerConnect(TreeLinkNode *pNode)
{
	if (pNode == 0 || pNode->left == 0 || pNode->right == 0)
		return;
	TreeLinkNode *leftRightChild = pNode->left;
	TreeLinkNode *rightLeftChild = pNode->right;
	while (leftRightChild && rightLeftChild)
	{
		leftRightChild->next = rightLeftChild;
		leftRightChild = leftRightChild->right;
		rightLeftChild = rightLeftChild->left;
	}
	InnerConnect(pNode->left);
	InnerConnect(pNode->right);
}

void connect(TreeLinkNode *root)
{
	InnerConnect(root);
}