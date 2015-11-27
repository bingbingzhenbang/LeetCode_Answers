//Given a list, rotate the list to the right by k places, where k is non - negative.
//
//For example :
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

#include "ListNode.h"

struct ListNode* reverseList(struct ListNode* head);

ListNode* rotateRight(ListNode* head, int k)
{
	if (head == 0 || head->next == 0)
		return head;
	int cnt = 0;
	for (ListNode *p = head; p != 0; ++cnt, p = p->next)
		;
	k = k % cnt;
	if (k == 0)
		return head;
	head = reverseList(head);
	ListNode *p = 0, *q = head, *r = 0;
	for (int i = 1; i < k; ++i, q = q->next)
		;
	r = q->next;
	q->next = 0;
	p = reverseList(head);
	r = reverseList(r);
	head->next = r;
	return p;
}