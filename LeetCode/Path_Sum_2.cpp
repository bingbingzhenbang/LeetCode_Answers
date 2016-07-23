//Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.
//
//For example :
//Given the below binary tree and sum = 22,
//5
/// \
//4   8
/// / \
//11  13  4
/// \ / \
//7    2  5   1
//return
//[
//	[5, 4, 11, 2],
//	[5, 8, 4, 5]
//]

#include "TreeNode.h"
#include <vector>

using namespace std;

vector<vector<int>> pathSum2(TreeNode* root, int sum)
{
	vector<vector<int>> result;
	if (root == 0)
		return result;
	else if (root->left == 0 && root->right == 0)
	{
		if (root->val == sum)
		{
			vector<int> vec(1, root->val);
			result.push_back(vec);
		}
		return result;
	}
	else if (root->left == 0)
	{
		vector<vector<int>> preresult = pathSum2(root->right, sum - root->val);
		for (int i = 0; i < preresult.size(); ++i)
		{
			vector<int> vec(1, root->val);
			for (int j = 0; j < preresult[i].size(); ++j)
				vec.push_back(preresult[i][j]);
			result.push_back(vec);
		}
		return result;
	}
	else if (root->right == 0)
	{
		vector<vector<int>> preresult = pathSum2(root->left, sum - root->val);
		for (int i = 0; i < preresult.size(); ++i)
		{
			vector<int> vec(1, root->val);
			for (int j = 0; j < preresult[i].size(); ++j)
				vec.push_back(preresult[i][j]);
			result.push_back(vec);
		}
		return result;
	}
	else
	{
		vector<vector<int>> leftresult = pathSum2(root->left, sum - root->val);
		for (int i = 0; i < leftresult.size(); ++i)
		{
			vector<int> vec(1, root->val);
			for (int j = 0; j < leftresult[i].size(); ++j)
				vec.push_back(leftresult[i][j]);
			result.push_back(vec);
		}
		vector<vector<int>> rightresult = pathSum2(root->right, sum - root->val);
		for (int i = 0; i < rightresult.size(); ++i)
		{
			vector<int> vec(1, root->val);
			for (int j = 0; j < rightresult[i].size(); ++j)
				vec.push_back(rightresult[i][j]);
			result.push_back(vec);
		}
		return result;
	}
}

void subtreePathSum(TreeNode* root, int sum, vector<int> &preList, vector<vector<int>> &result)
{
	if (root == 0)
		return;
	preList.push_back(root->val);
	if (root->left == 0 && root->right == 0 && root->val == sum)
	{
		result.push_back(preList);
	}
	else
	{
		subtreePathSum(root->left, sum - root->val, preList, result);
		subtreePathSum(root->right, sum - root->val, preList, result);
	}
	preList.pop_back();
}

vector<vector<int>> pathSum3(TreeNode* root, int sum)
{
	vector<vector<int>> result;
	vector<int> vec;
	subtreePathSum(root, sum, vec, result);
	return result;
}