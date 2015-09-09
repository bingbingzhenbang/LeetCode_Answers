//Given a linked list, determine if it has a cycle in it. 
//
//	Follow up:
//Can you solve it without using extra space? 

#include "ListNode.h"
#include <cstdlib>

bool hasCycle(struct ListNode *head)
{
	struct ListNode *p = head, *q = head;
	while (p != NULL && q != NULL)
	{
		p = p->next;
		q = q->next;
		if (q != NULL)
			q = q->next;
		if (p != NULL && p == q)
			return true;
	} 
	return false;
}
