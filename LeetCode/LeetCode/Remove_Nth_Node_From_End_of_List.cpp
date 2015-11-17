//Given a linked list, remove the nth node from the end of list and return its head.
//
//	For example,
//	Given linked list: 1->2->3->4->5, and n = 2.
//
//	After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//
//Note:
//Given n will always be valid.
//	Try to do this in one pass. 

#include "ListNode.h"

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode *p = head, *q = head;
	for (int i = 1; i < n && q != 0; q = q->next, ++i)
		;
	if (q == 0)
		return head;
	else if (q->next == 0)
	{
		head = p->next;
		delete p;
		return head;
	}
	else
	{
		if (n == 1)
		{
			while (q->next != 0)
			{
				p = q;
				q = q->next;
			}
			p->next = 0;
			delete q;
		}
		else
		{
			ListNode *r = 0;
			while (q->next != 0)
			{
				r = p;
				p = p->next;
				q = q->next;
			}
			r->next = p->next;
			delete p;
		}
	}
	return head;
}

void testRemoveNthFromEnd()
{
	ListNode *p = new ListNode;
	p->val = 1;
	p->next = new ListNode;
	p->next->val = 2;
	p->next->next = 0;
	p->next->next = new ListNode;
	p->next->next->val = 3;
	p->next->next->next = 0;
	ListNode *r = removeNthFromEnd(p, 1);
}