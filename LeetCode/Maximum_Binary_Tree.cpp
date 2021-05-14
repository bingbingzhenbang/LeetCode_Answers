#include "TreeNode.h"
#include <vector>
#include <map>

using namespace std;

void addToBinaryTree(TreeNode *&root, pair<const int, int> &newPair, map<int, int> &value2Index)
{
	if (root == nullptr)
	{
		root = new TreeNode(newPair.first);
		return;
	}
	int rootIndex = value2Index[root->val];
	if (newPair.second > rootIndex)
		addToBinaryTree(root->right, newPair, value2Index);
	else if (newPair.second < rootIndex)
		addToBinaryTree(root->left, newPair, value2Index);
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	map<int, int> value2Index;
	int N = nums.size();
	for (int i = 0; i < N; ++i)
		value2Index[nums[i]] = i;
	TreeNode *root = nullptr;
	for (auto itr = value2Index.rbegin(); itr != value2Index.rend(); ++itr)
	{
		addToBinaryTree(root, *itr, value2Index);
	}
	return root;
}