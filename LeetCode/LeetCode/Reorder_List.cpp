//Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
//	reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­ 
//
//	You must do this in-place without altering the nodes' values.
//
//	For example,
//	Given {1,2,3,4}, reorder it to {1,4,2,3}. 

#include "ListNode.h"
#include <cstdlib>

struct ListNode* reverseList(struct ListNode* head);

void reorderList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return;
	struct ListNode *p, *q, *second_head;
	int node_cnt = 0;
	for (p = head; p != NULL; p = p->next, ++node_cnt)
		;
	for (p = head, q = head; q != NULL && q->next != NULL; p = p->next,  q = q->next->next)
		;
	if (node_cnt % 2 == 1)
		second_head = p->next;
	else
		second_head = p;
	for (p = head; p != NULL; p = p->next)
	{
		if (p->next == second_head)
		{
			p->next = NULL;
			break;
		}
	}
	second_head = reverseList(second_head);
	struct ListNode *r, *s;
	for (q = second_head, p = head; q != NULL && p != NULL;)
	{
		r = p->next;
		s = q->next;
		p->next = q;
		q->next = r;
		p = r;
		q = s;
	}
	return;
}