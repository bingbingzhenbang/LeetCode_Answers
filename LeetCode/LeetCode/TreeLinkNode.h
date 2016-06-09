#ifndef TREELINKNODE_H
#define TREELINKNODE_H

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x = 0) : val(x), left(0), right(0), next(0){}
};

#endif // TREELINKNODE_H