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
#include <queue>
#include <utility>

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

vector<vector<int>> levelOrder2(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == 0)
		return result;
	queue< pair<int, TreeNode*> > level_order;
	level_order.push(pair<int, TreeNode*>(0, root));
	while (!level_order.empty())
	{
		int level = level_order.front().first;
		TreeNode* pNode = level_order.front().second;
		int val = pNode->val;
		level_order.pop();
		if (level == result.size())
			result.push_back(vector<int>());
		result[level].push_back(val);
		if (pNode->left)
			level_order.push(pair<int, TreeNode*>(level + 1, pNode->left));
		if (pNode->right)
			level_order.push(pair<int, TreeNode*>(level + 1, pNode->right));
	}
	return result;
}