#include "TreeNode.h"
#include <vector>

using namespace std;

void leafNodeList(TreeNode* root, vector<TreeNode*> &leafList)
{
	if (root == nullptr)
		return;
	if (root->left)
		leafNodeList(root->left, leafList);
	if (root->right)
		leafNodeList(root->right, leafList);
	if (root->left == nullptr && root->right == nullptr)
		leafList.push_back(root);
}

bool nodeListSimilar(const vector<TreeNode*> &l1, const vector<TreeNode*> &l2)
{
	if (l1.size() != l2.size())
		return false;
	int sz = l1.size();
	for (int i = 0; i < sz; ++i)
	{
		if (l1[i]->val != l2[i]->val)
			return false;
	}
	return true;
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	vector<TreeNode*> l1, l2;
	leafNodeList(root1, l1);
	leafNodeList(root2, l2);
	return nodeListSimilar(l1, l2);
}