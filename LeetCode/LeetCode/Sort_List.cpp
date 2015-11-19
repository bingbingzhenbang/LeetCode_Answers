//Sort a linked list in O(n log n) time using constant space complexity.

#include "ListNode.h"

ListNode* mergeList(ListNode* left, ListNode* right)
{
	ListNode *p = left, *q = right, *head, *r = left;
	head = (p->val < q->val) ? p : q;
	while (p != 0 && q != 0)
	{
		if (p->val < q->val)
		{
			while (p != 0 && p->val < q->val)
			{
				r = p;
				p = p->next;
			}
			r->next = q;
		}
		else
		{
			while (q != 0 && q->val <= p->val)
			{
				r = q;
				q = q->next;
			}
			r->next = p;
		}
	}
	return head;
}

ListNode* mergeListSort(ListNode* head)
{
	if (head == 0 || head->next == 0)
		return head;
	ListNode *p = head, *q = head, *r = head;
	while (q != 0 && q->next != 0)
	{
		r = p;
		p = p->next;
		q = q->next->next;
	}
	ListNode *right = r->next;
	r->next = 0;
	head = mergeListSort(head);
	right = mergeListSort(right);
	head = mergeList(head, right);
	return head;
}

ListNode* sortList(ListNode* head)
{
	if (head == 0 || head->next == 0)
		return head;
	return mergeListSort(head);
}

void testSortList()
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
	ListNode *r = sortList(p);
}