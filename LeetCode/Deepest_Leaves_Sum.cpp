#include "TreeNode.h"
#include <algorithm>

int getDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	return std::max(getDepth(root->left), getDepth(root->right)) + 1;
}
void addToSum(TreeNode *root, int currentDepth, int maxDepth, int &sum)
{
	if (root == nullptr)
		return;
	if (currentDepth == maxDepth)
	{
		sum += root->val;
		return;
	}
	addToSum(root->left, currentDepth + 1, maxDepth, sum);
	addToSum(root->right, currentDepth + 1, maxDepth, sum);
}
int deepestLeavesSum(TreeNode* root)
{
	int depth = getDepth(root);
	int currentSum = 0;
	addToSum(root, 1, depth, currentSum);
	return currentSum;
}