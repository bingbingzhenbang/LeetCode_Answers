//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia :
//In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.It can have between 1 and 2h nodes inclusive at the last level h.

#include "TreeNode.h"

int getLeftSubTreeHeight(TreeNode *root)
{
	int cnt = 0;
	for (; root->left; root = root->left, ++cnt)
		;
	return cnt;
}

int getRightSubTreeHeight(TreeNode *root)
{
	int cnt = 0;
	for (; root->right; root = root->right, ++cnt)
		;
	return cnt;
}

int countNodes(TreeNode* root)
{
	if (root == 0)
		return 0;
	int L = getLeftSubTreeHeight(root), R = getRightSubTreeHeight(root);
	if (L == R)
		return (1 << (L + 1)) - 1;
	else
		return countNodes(root->left) + countNodes(root->right) + 1;
}