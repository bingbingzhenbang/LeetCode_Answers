//Reverse a singly linked list.
//
//	click to show more hints.
//
//Hint: 
//A linked list can be reversed either iteratively or recursively. Could you implement both?

#include "ListNode.h"
#include <cstdlib>

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode *p = head, *q, *r;
	if (p == NULL)
		return p;
	else
	{
		q = p->next;
		p->next = NULL;		
	}
	while (q != NULL)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	return p;
}