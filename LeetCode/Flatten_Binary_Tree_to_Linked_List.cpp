//Given a binary tree, flatten it to a linked list in - place.
//
//For example,
//Given
//1
/// \
//2   5
/// \   \
//3   4   6
//
//
//The flattened tree should look like :
//1
//\
//2
//\
//3
//\
//4
//\
//5
//\
//6
//
//
//click to show hints.
//
//Hints:
//If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

#include "TreeNode.h"

using namespace std;

TreeNode* flattenSubTree(TreeNode *pNode)
{
	if (pNode == 0 || (pNode && pNode->left == 0 && pNode->right == 0))
		return pNode;
	else
	{
		TreeNode *prevLeft = pNode->left, *prevRight = pNode->right;
		if (prevLeft == 0)
		{
			pNode->right = flattenSubTree(prevRight);
			return pNode;
		}
		else
		{
			pNode->right = flattenSubTree(prevLeft);
			pNode->left = 0;
			if (pNode->right)
			{
				TreeNode *temp = pNode->right;
				while (temp->right)
					temp = temp->right;
				temp->right = flattenSubTree(prevRight);
				temp->left = 0;
			}
			return pNode;
		}
	}
}

void flatten(TreeNode* root)
{
	flattenSubTree(root);
}