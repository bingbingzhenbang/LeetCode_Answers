//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//Note: Do not modify the linked list.
//
//	  Follow up :
//Can you solve it without using extra space ?

#include "ListNode.h"

ListNode *detectCycle(ListNode *head)
{
	ListNode *p = head, *q = head;
	while (p != 0 && q != 0)
	{
		p = p->next;
		q = q->next;
		if (q != 0)
			q = q->next;
		if (p != 0 && p == q)
		{
			ListNode *r = head, *s = p;
			while (r != s)
			{
				r = r->next;
				s = s->next;
			}
			return r;
		}
	}
	return 0;
}