//The thief has found himself a new place for his thievery again.There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house.After a tour, the smart thief realized that "all houses in this place forms a binary tree".It will automatically contact the police if two directly - linked houses were broken into on the same night.
//
//Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
//Example 1:
//
//3
/// \
//2   3
//\   \
//3   1
//
//Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//
//Example 2:
//
//3
/// \
//4   5
/// \   \
//1   3   1
//
//Maximum amount of money the thief can rob = 4 + 5 = 9.

#include "TreeNode.h"
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> robNode(TreeNode *pNode)
{
	if (pNode == 0)
		return pair<int, int>(0, 0);
	pair<int, int> l = robNode(pNode->left);
	pair<int, int> r = robNode(pNode->right);
	int yes, no;
	yes = l.second + r.second + pNode->val;
	no = max(l.first, l.second) + max(r.first, r.second);
	return pair<int, int>(yes, no);
}

int rob(TreeNode* root)
{
	pair<int, int> rt = robNode(root);
	return max(rt.first, rt.second);
}