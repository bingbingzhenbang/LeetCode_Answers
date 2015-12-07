#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x = 0) : val(x), next(0) {}
};

#endif // 