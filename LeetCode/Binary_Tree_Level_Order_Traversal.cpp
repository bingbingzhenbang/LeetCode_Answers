//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
//return its level order traversal as :
//
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]

#include "TreeNode.h"
#include <vector>

using namespace std;

void levelTraverse(TreeNode *pNode, int level, vector<vector<int>> &L)
{
	if (pNode != 0)
	{
		if (L.size() == level)
			L.push_back(vector<int>());
		L[level].push_back(pNode->val);
		levelTraverse(pNode->left, level + 1, L);
		levelTraverse(pNode->right, level + 1, L);
	}
}

vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	levelTraverse(root, 0, result);
	return result;
}