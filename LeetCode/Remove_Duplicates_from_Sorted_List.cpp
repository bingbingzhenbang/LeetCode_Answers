//Given a sorted linked list, delete all duplicates such that each element appear only once. 
//
//	For example,
//	Given 1->1->2, return 1->2.
//	Given 1->1->2->3->3, return 1->2->3. 
//

#include "ListNode.h"
#include <cstdlib>

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode *p, *q;
	if (head == NULL)
		return NULL;
	p = head;
	q = head->next;
	while (q != NULL)
	{
		while (q != NULL && p->val == q->val)
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
		p = q;
		if (p != NULL)
			q = p->next;
		else
			break;
	}
	return head;
}