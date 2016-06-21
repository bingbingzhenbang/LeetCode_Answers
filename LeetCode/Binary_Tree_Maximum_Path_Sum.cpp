//Given a binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent - child connections.The path does not need to go through the root.
//
//For example :
//Given the below binary tree,
//1
/// \
//2   3
//
//
//
//Return 6.

#include "TreeNode.h"
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> maxSubTreePathSum(TreeNode *pNode)
{
	if (pNode == 0)
		return pair<int, int>(0, 0);
	else if (pNode->left == 0 && pNode->right == 0)
		return pair<int, int>(pNode->val, pNode->val);
	else if (pNode->left == 0)
	{
		pair<int, int> right_result = maxSubTreePathSum(pNode->right);
		int max_toroot = max(pNode->val, right_result.first + pNode->val);
		int max_insubtree = max(max_toroot, right_result.second);
		return pair<int, int>(max_toroot, max_insubtree);
	}
	else if (pNode->right == 0)
	{
		pair<int, int> left_result = maxSubTreePathSum(pNode->left);
		int max_toroot = max(pNode->val, left_result.first + pNode->val);
		int max_insubtree = max(max_toroot, left_result.second);
		return pair<int, int>(max_toroot, max_insubtree);
	}
	else
	{
		pair<int, int> left_result = maxSubTreePathSum(pNode->left);
		pair<int, int> right_result = maxSubTreePathSum(pNode->right);
		int max_toroot = max(pNode->val, max(left_result.first, right_result.first) + pNode->val);
		int max_insubtree = max(max(max(left_result.second, right_result.second), max_toroot), left_result.first + right_result.first + pNode->val);
		return pair<int, int>(max_toroot, max_insubtree);
	}
}

int maxPathSum(TreeNode* root)
{
	pair<int, int> rt = maxSubTreePathSum(root);
	return max(rt.first, rt.second);
}

void testMaxPathSum()
{
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(-1);
	int rt = maxPathSum(root);
}
