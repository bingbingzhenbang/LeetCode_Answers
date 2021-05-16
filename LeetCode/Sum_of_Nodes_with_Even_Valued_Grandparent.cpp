#include "TreeNode.h"

void sumEvenGrandparent(TreeNode* root, int &sum)
{
	if (root == nullptr)
		return;
	bool rootEven = (root->val % 2 == 0);
	if (root->left)
	{
		if (rootEven)
		{
			if (root->left->left)
				sum += root->left->left->val;
			if (root->left->right)
				sum += root->left->right->val;
		}
		sumEvenGrandparent(root->left, sum);
	}
	if (root->right)
	{
		if (rootEven)
		{
			if (root->right->left)
				sum += root->right->left->val;
			if (root->right->right)
				sum += root->right->right->val;
		}
		sumEvenGrandparent(root->right, sum);
	}
}

int sumEvenGrandparent(TreeNode* root) {
	int sum = 0;
	sumEvenGrandparent(root, sum);
	return sum;
}