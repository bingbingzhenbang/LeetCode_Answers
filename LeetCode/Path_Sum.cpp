//Given a binary tree and a sum, determine if the tree has a root - to - leaf path such that adding up all the values along the path equals the given sum.
//For example :
//Given the below binary tree and sum = 22, 5
/// \
//4   8
/// / \
//11  13  4
/// \      \
//7    2      1
//
//
//return true, as there exist a root - to - leaf path 5->4->11->2 which sum is 22.

#include "TreeNode.h"

using namespace std;

bool hasPathSum(TreeNode* root, int sum)
{
	if (root == 0)
		return false;
	if (root->left == 0 && root->right == 0)
		return root->val == sum;
	else if (root->left == 0)
		return hasPathSum(root->right, sum - root->val);
	else if (root->right == 0)
		return hasPathSum(root->left, sum - root->val);
	else
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}