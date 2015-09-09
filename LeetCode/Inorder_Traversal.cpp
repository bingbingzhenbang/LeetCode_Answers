//Given a binary tree, return the inorder traversal of its nodes' values.
//
//	For example:
//Given binary tree {1,#,2,3},
//
//	1
//	\
//	2
//	/
//	3
//
//
//
//	return [1,3,2]. 
//
//Note: Recursive solution is trivial, could you do it iteratively?

#include "TreeNode.h"
#include <vector>
#include <stack>

using namespace std;

vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> result;
	TreeNode *p = root;
	stack<TreeNode*> nodestack;
	do 
	{
		while (p != NULL)
		{
			nodestack.push(p);
			p = p->left;
		}
		if (!nodestack.empty())
		{
			p = nodestack.top();
			nodestack.pop();
			result.push_back(p->val);
			p = p->right;
		}
	} while (p != NULL || !nodestack.empty());
	return result;
}