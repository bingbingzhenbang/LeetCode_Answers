//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//	For example, this binary tree is symmetric: 
//1
//	/ \
//	2   2
//	/ \ / \
//	3  4 4  3
//
//
//
//	But the following is not:
//
//1
//	/ \
//	2   2
//	\   \
//	3    3
//
//
//
//Note:
//Bonus points if you could solve it both recursively and iteratively. 
//

#include "TreeNode.h"
#include <cstdlib>

bool isSubTreeSymmetric(struct TreeNode *p, struct TreeNode *q)
{
	if (p == NULL && q == NULL)
		return true;
	else if (p != NULL && q != NULL && p->val == q->val)
	{
		if (isSubTreeSymmetric(p->left, q->right))
			return isSubTreeSymmetric(p->right, q->left);
		else
			return false;
	}
	else
		return false;
}

bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
		return true;
	else
		return isSubTreeSymmetric(root->left, root->right);
}