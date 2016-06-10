//Follow up for problem "Populating Next Right Pointers in Each Node".
//
//What if the given tree could be any binary tree ? Would your previous solution still work ?
//
//Note :
//	 You may only use constant extra space.
//
//
//	 For example,
//	 Given the following binary tree,
//
//	 1
//	 / \
//	 2    3
//	 / \    \
//	 4   5    7
//
//
//
//	 After calling your function, the tree should look like :
//
//1->NULL
/// \
//2 -> 3->NULL
/// \    \
//4-> 5 -> 7->NULL

#include "TreeLinkNode.h"

using namespace std;

void connect3(TreeLinkNode *root)
{
	TreeLinkNode *prevBegin = root;
	while (prevBegin)
	{
		TreeLinkNode *prevItr = prevBegin;
		while (prevItr && prevItr->left == 0 && prevItr->right == 0)
			prevItr = prevItr->next;
		prevBegin = prevItr;
		while (prevItr)
		{
			TreeLinkNode *prevNext = prevItr->next;
			while (prevNext && prevNext->left == 0 && prevNext->right == 0)
				prevNext = prevNext->next;
			TreeLinkNode *leftChild = prevItr->left, *rightChild = prevItr->right, *nextChild = 0;
			if (prevNext)
			{
				if (prevNext->left)
					nextChild = prevNext->left;
				else
					nextChild = prevNext->right;
			}
			if (leftChild)
			{
				if (rightChild)
				{
					leftChild->next = rightChild;
					rightChild->next = nextChild;
				}
				else
					leftChild->next = nextChild;
			}
			else if (rightChild)
				rightChild->next = nextChild;
			prevItr = prevNext;
		}
		if (prevBegin)
		{
			if (prevBegin->left)
				prevBegin = prevBegin->left;
			else
				prevBegin = prevBegin->right;
		}
	}
}