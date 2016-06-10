//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

#include "TreeNode.h"
#include <vector>
#include <algorithm>

using namespace std;

TreeNode* buildSubTree(vector<int>::iterator preItr, vector<int>::iterator inItr, int size)
{
	if (size == 0)
		return 0;
	int rootVal = *preItr;
	TreeNode *pNode = new TreeNode(rootVal);
	int mid = find(inItr, inItr + size, rootVal) - inItr;
	pNode->left = buildSubTree(preItr + 1, inItr, mid);
	pNode->right = buildSubTree(preItr + 1 + mid, inItr + 1 + mid, size - mid - 1);
	return pNode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	return buildSubTree(preorder.begin(), inorder.begin(), preorder.size());
}