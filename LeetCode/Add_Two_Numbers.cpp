#include "ListNode.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *p1 = l1, *p2 = l2;
	ListNode *retNode = nullptr, *prevNode = nullptr, *currentNode = nullptr;
	int remainVal = 0;
	while (p1 || p2)
	{
		int tempVal = remainVal;
		if (p1)
			tempVal += p1->val;
		if (p2)
			tempVal += p2->val;
		int nodeVal = tempVal % 10;
		remainVal = tempVal / 10;
		currentNode = new ListNode(nodeVal);
		if (retNode == nullptr)
		{
			retNode = prevNode = currentNode;
		}
		else
		{
			prevNode->next = currentNode;
			prevNode = currentNode;
		}
		if (p1)
			p1 = p1->next;
		if (p2)
			p2 = p2->next;
	}
	while (remainVal)
	{
		int nodeVal = remainVal % 10;
		remainVal = remainVal / 10;
		currentNode = new ListNode(nodeVal);
		if (retNode == nullptr)
		{
			retNode = prevNode = currentNode;
		}
		else
		{
			prevNode->next = currentNode;
			prevNode = currentNode;
		}
	}
	return retNode;
}