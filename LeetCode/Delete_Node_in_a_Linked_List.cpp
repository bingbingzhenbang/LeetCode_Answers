//Write a function to delete a node (except the tail) in a singly linked list, given only access to that node. 
//
//	Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function. 

#include <cstdlib>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

void deleteNode(struct ListNode* node)
{
	struct ListNode *p = node, *q = node->next, *r;
	for (; q != NULL; p = q, q = q->next)
	{
		r = p;
		p->val = q->val;
	}
	r->next = NULL;
	free(p);
}

void testdeleteNode()
{
	struct ListNode *p1, *p2, *p3, *p4;
	p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p4 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p1->val = 1;
	p2->val = 2;
	p3->val = 3;
	p4->val = 4;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = NULL;
	deleteNode(p1);
}
