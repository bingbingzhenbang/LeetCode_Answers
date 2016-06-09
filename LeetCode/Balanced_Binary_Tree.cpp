//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

#include "TreeNode.h"
#include <algorithm>

using namespace std;

bool isSubTreeBalanced(int &depth, TreeNode *pNode)
{
	if (pNode == 0)
	{
		depth = 0;
		return true;
	}
	int left_depth = 0, right_depth = 0;
	if (isSubTreeBalanced(left_depth, pNode->left) && isSubTreeBalanced(right_depth, pNode->right))
	{
		int diff = left_depth - right_depth;
		if (diff >= -1 && diff <= 1)
		{
			depth = 1 + max(left_depth, right_depth);
			return true;
		}
	}
	return false;
}

bool isBalanced(TreeNode* root)
{
	int depth = 0;
	return isSubTreeBalanced(depth, root);
}