//Given a singly linked list, determine if it is a palindrome.
//
//	Follow up:
//Could you do it in O(n) time and O(1) space?

#include "ListNode.h"
#include <cstdlib>

struct ListNode* reverseList(struct ListNode* head);

bool isPalindrome(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return true;
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
	second_head = reverseList(second_head);
	for (q = second_head, p = head; q != NULL; q = q->next, p = p->next)
	{
		if (q->val != p->val)
			return false;
	}
	return true;
}

void testIsPalindrome()
{
	struct ListNode *p;
	p = (struct ListNode *)malloc(sizeof(struct ListNode));
	p->val = 1;
	p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	p->next->val = 3;
	p->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	p->next->next->val = 1;
	p->next->next->next = NULL;
	bool rt = isPalindrome(p);
}