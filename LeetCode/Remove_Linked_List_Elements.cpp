//Remove all elements from a linked list of integers that have value val.
//
//	Example
//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5 

#include "ListNode.h"
#include <cstdlib>

struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
		return NULL;
	struct ListNode *p = head, *q;
	while (p != NULL && p->val == val)
	{
		q = p;
		p = p->next;
		free(q);
	}
	head = p;
	while (p != NULL)
	{
		if (p->next != NULL && p->next->val == val)
		{
			q = p->next;
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
	return head;
}