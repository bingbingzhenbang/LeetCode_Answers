//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note: 
//You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.
//
//	Follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

#include "TreeNode.h"
#include <cstdlib>

int subTreeNodeCount(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return subTreeNodeCount(root->left) + subTreeNodeCount(root->right) + 1;
}

int kthSmallest(struct TreeNode* root, int k)
{
	if (root == NULL)
		return 0;
	int L = subTreeNodeCount(root->left);
	if (L == k - 1)
		return root->val;
	else if (L >= k)
		return kthSmallest(root->left, k);
	else
		return kthSmallest(root->right, k - L - 1);
}