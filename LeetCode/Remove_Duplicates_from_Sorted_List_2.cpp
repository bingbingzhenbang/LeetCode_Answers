//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
//
//	For example,
//	Given 1->2->3->3->4->4->5, return 1->2->5.
//	Given 1->1->1->2->3, return 2->3. 

#include "ListNode.h"

ListNode* deleteDuplicates2(ListNode* head)
{
	if (head == 0 || head->next == 0)
		return head;
	ListNode *p = head, *q = head->next, *r = 0;
	bool has_deleted_repeat = false;
	while (q != 0)
	{
		while (q != 0 && q->val == p->val)
		{
			p->next = q->next;
			delete q;
			has_deleted_repeat = true;
			q = p->next;
		}
		if (has_deleted_repeat)
		{
			if (p == head)
			{
				delete p;
				head = q;
			}
			else
			{
				if (r)
					r->next = q;
				delete p;
			}
			has_deleted_repeat = false;
		}
		else
		{
			r = p;
		}
		p = q;
		if (p)
			q = p->next;
	}
	return head;
}

void testDeleteDuplicates2()
{
	ListNode *p = new ListNode;
	p->val = 1;
	p->next = new ListNode;
	p->next->val = 2;
	p->next->next = new ListNode;
	p->next->next->val = 3;
	p->next->next->next = new ListNode;
	p->next->next->next->val = 3;
	p->next->next->next->next = new ListNode;
	p->next->next->next->next->val = 4;
	p->next->next->next->next->next = new ListNode;
	p->next->next->next->next->next->val = 4;
	p->next->next->next->next->next->next = new ListNode;
	p->next->next->next->next->next->next->val = 5;
	p->next->next->next->next->next->next->next = 0;
	ListNode *r = deleteDuplicates2(p);
}