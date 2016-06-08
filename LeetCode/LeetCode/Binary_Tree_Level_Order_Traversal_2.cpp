//Given a binary tree, return the bottom - up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//
//3
/// \
//9  20
/// \
//15   7
//
//
//
//return its bottom - up level order traversal as :
//
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]

#include "TreeNode.h"
#include <vector>

using namespace std;

void levelTraverse2(TreeNode *pNode, int level, vector< vector<int> > &L)
{
	if (pNode != 0)
	{
		if (level == L.size())
			L.push_back(vector<int>());
		L[level].push_back(pNode->val);
		levelTraverse2(pNode->left, level + 1, L);
		levelTraverse2(pNode->right, level + 1, L);
	}
}

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector< vector<int> > L;
	levelTraverse2(root, 0, L);
	vector< vector<int> > result(L.rbegin(), L.rend());
	return result;
}

void testLevelOrderBottom()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	vector< vector<int> > rt = levelOrderBottom(root);
}