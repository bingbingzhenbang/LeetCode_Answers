//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

#include "ListNode.h"
#include <cstdlib>

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *p1 = l1, *p2 = l2, *r;
	if (p1 == NULL && p2 == NULL)
		return NULL;
	else if (p1 == NULL && p2 != NULL)
		return p2;
	else if (p1 != NULL && p2 == NULL)
		return p1;
	else
	{
		struct ListNode *head = (p1->val < p2->val) ? p1 : p2;
		while (p1 != NULL && p2 != NULL)
		{
			if (p1->val < p2->val)
			{
				while (p1->next != NULL && p1->next->val < p2->val)
					p1 = p1->next;
				r = p1->next;
				p1->next = p2;
				p1 = r;
			}
			else
			{
				while (p2->next != NULL && p2->next->val <= p1->val)
					p2 = p2->next;
				r = p2->next;
				p2->next = p1;
				p2 = r;
			}
		}
		return head;
	}
}