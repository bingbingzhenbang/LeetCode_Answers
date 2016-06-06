//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

#include "TreeNode.h"
#include <algorithm>

using namespace std;

int minDepth(TreeNode* root)
{
	if (root == 0)
		return 0;
	if (root->left == 0 && root->right == 0)
		return 1;
	else if (root->left == 0)
		return 1 + minDepth(root->right);
	else if (root->right == 0)
		return 1 + minDepth(root->left);
	else
		return 1 + min(minDepth(root->left), minDepth(root->right));
}