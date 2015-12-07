#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x = 0) : val(x), left(0), right(0) {}
};

#endif // TREENODE_H