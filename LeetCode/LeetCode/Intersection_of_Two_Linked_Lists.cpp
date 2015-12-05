//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists :
//A : a1 ¡ú a2
//	¨K
//	c1 ¡ú c2 ¡ú c3
//	¨J
//B : b1 ¡ú b2 ¡ú b3
//
//
//	begin to intersect at node c1.
//
//
//Notes :
//	  If the two linked lists have no intersection at all, return null.
//	  The linked lists must retain their original structure after the function returns.
//	  You may assume there are no cycles anywhere in the entire linked structure.
//	  Your code should preferably run in O(n) time and use only O(1) memory.

#include "ListNode.h"

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	int lengthA = 0, lengthB = 0;
	ListNode *pa = headA, *pb = headB;
	while (pa)
	{
		pa = pa->next;
		++lengthA;
	}
	while (pb)
	{
		pb = pb->next;
		++lengthB;
	}
	if (lengthA <= lengthB)
	{
		int diff = lengthB - lengthA;
		pa = headA;
		pb = headB;
		while (diff)
		{
			pb = pb->next;
			--diff;
		}
	}
	else
	{
		int diff = lengthA - lengthB;
		pa = headA;
		pb = headB;
		while (diff)
		{
			pa = pa->next;
			--diff;
		}
	}
	while (pa != pb)
	{
		pa = pa->next;
		pb = pb->next;
	}
	return pa;
}
