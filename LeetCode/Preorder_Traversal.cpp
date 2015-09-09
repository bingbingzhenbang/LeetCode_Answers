//Given a binary tree, return the preorder traversal of its nodes' values.
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
//	return [1,2,3]. 

#include "TreeNode.h"
#include <vector>
#include <stack>

using namespace std;

vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> result;
	TreeNode *p = root;
	stack<TreeNode*> nodestack;
	nodestack.push(NULL);
	while (p != NULL)
	{
		result.push_back(p->val);
		if (p->right != NULL)
			nodestack.push(p->right);
		if (p->left != NULL)
			p = p->left;
		else
		{
			p = nodestack.top();
			nodestack.pop();
		}
	}
	return result;
}