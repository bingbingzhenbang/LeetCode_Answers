//Given a linked list, swap every two adjacent nodes and return its head. 
//
//	For example,
//	Given 1->2->3->4, you should return the list as 2->1->4->3. 
//
//	Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 

#include "ListNode.h"

ListNode* swapPairs(ListNode* head)
{
	if (head == 0 || head->next == 0)
		return head;
	ListNode *p = 0, *q = 0, *r = 0, *s = 0, *rt = 0;
	p = head;
	q = p->next;
	rt = q;
	while (q != 0)
	{
		r = q->next;
		if (r != 0)
		{
			s = r->next;
			if (s != 0)
			{
				q->next = p;
				p->next = s;
				p = r;
				q = s;
			}
			else
			{
				q->next = p;
				p->next = r;
				break;
			}
		}
		else
		{
			q->next = p;
			p->next = 0;
			break;
		}
	}
	return rt;
}

void testSwapPairs()
{
	ListNode *p = new ListNode;
	p->val = 1;
	p->next = new ListNode;
	p->next->val = 2;
	p->next->next = new ListNode;
	p->next->next->val = 3;
	p->next->next->next = 0;
	ListNode *r = swapPairs(p);
}