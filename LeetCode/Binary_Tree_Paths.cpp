//Given a binary tree, return all root - to - leaf paths.
//
//For example, given the following binary tree :
//
//
//1
/// \
//2     3
//\
//5
//
//
//
//All root - to - leaf paths are :
//["1->2->5", "1->3"]

#include "TreeNode.h"
#include <vector>
#include <string>

using namespace std;

void binaryTreePath(vector<string> &result, TreeNode *pNode, string str)
{
	if (pNode->left == 0 && pNode->right == 0)
		result.push_back(str);
	if (pNode->left)
		binaryTreePath(result, pNode->left, str + "->" + to_string(pNode->left->val));
	if (pNode->right)
		binaryTreePath(result, pNode->right, str + "->" + to_string(pNode->right->val));
}

vector<string> binaryTreePaths(TreeNode* root)
{
	vector<string> rt;
	if (root == 0)
		return rt;
	binaryTreePath(rt, root, to_string(root->val));
	return rt;
}