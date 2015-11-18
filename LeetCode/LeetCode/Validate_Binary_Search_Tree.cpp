//Given a binary tree, determine if it is a valid binary search tree (BST). 
//
//	Assume a BST is defined as follows: 
//     The left subtree of a node contains only nodes with keys less than the node's key.
//	 The right subtree of a node contains only nodes with keys greater than the node's key.
//	Both the left and right subtrees must also be binary search trees.

#include "TreeNode.h"

TreeNode* minimumNode(TreeNode* root)
{
	TreeNode* ptr = root;
	while (ptr->left != 0)
		ptr = ptr->left;
	return ptr;
}

TreeNode* maximumNode(TreeNode* root)
{
	TreeNode* ptr = root;
	while (ptr->right != 0)
		ptr = ptr->right;
	return ptr;
}

bool isValidBST(TreeNode* root)
{
	if (root == 0)
		return true;
	if (root->left != 0)
	{
		if ( !(root->left->val < root->val && isValidBST(root->left) && maximumNode(root->left)->val < root->val) )
			return false;
	}
	if (root->right != 0)
	{
		if ( !(root->right->val > root->val && isValidBST(root->right) && minimumNode(root->right)->val > root->val) )
			return false;
	}
	return true;
}