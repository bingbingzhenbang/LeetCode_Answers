//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

#include "ListNode.h"
#include "TreeNode.h"

using namespace std;

TreeNode* sortedListToSubBST(ListNode *head, ListNode *tail)
{
	if (head == tail)
		return 0;
	if (head->next == tail)
		return new TreeNode(head->val);
	ListNode *p = head, *q = head;
	for (; q != tail && q->next != tail; p = p->next, q = q->next->next)
		;
	TreeNode *midNode = new TreeNode(p->val);
	midNode->left = sortedListToSubBST(head, p);
	midNode->right = sortedListToSubBST(p->next, tail);
	return midNode;
}

TreeNode* sortedListToBST(ListNode* head)
{
	return sortedListToSubBST(head, 0);
}