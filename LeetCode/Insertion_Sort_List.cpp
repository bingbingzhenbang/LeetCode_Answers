//Sort a linked list using insertion sort.

#include "ListNode.h"

ListNode* insertNode(ListNode *head, ListNode *p)
{
	if (p == 0)
		return head;
	if (head == 0)
	{
		head = p;
		head->next = 0;
	}
	else
	{
		if (p->val < head->val)
		{
			p->next = head;
			head = p;
		}
		else
		{
			ListNode *r = 0, *q = head;
			while (q != 0 && q->val <= p->val)
			{
				r = q;
				q = q->next;
			}
			r->next = p;
			p->next = q;
		}
	}
	return head;
}

ListNode* insertionSortList(ListNode* head)
{
	if (head == 0 || head->next == 0)
		return head;
	ListNode *newHead = 0;
	while (head != 0)
	{
		ListNode *p = head;
		head = head->next;
		p->next = 0;
		newHead = insertNode(newHead, p);
	}
	return newHead;
}

void testInsertionSortList()
{
	ListNode *p = new ListNode;
	p->val = 7;
	p->next = new ListNode;
	p->next->val = 5;
	p->next->next = new ListNode;
	p->next->next->val = 9;
	p->next->next->next = new ListNode;
	p->next->next->next->val = 1;
	p->next->next->next->next = new ListNode;
	p->next->next->next->next->val = 3;
	p->next->next->next->next->next = new ListNode;
	p->next->next->next->next->next->val = 10;
	//p->next->next->next->next->next->next = 0;
	p->next->next->next->next->next->next = new ListNode;
	p->next->next->next->next->next->next->val = 2;
	p->next->next->next->next->next->next->next = 0;
	ListNode *r = insertionSortList(p);
}