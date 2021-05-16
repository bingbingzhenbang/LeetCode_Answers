#include <vector>

using namespace std;
#include "Node.h"

Node* cloneTree(Node* root) {
	if (root == nullptr)
		return nullptr;
	Node *ret = new Node(root->val);
	int N = root->children.size();
	for (int i = 0; i < N; ++i)
	{
		Node *child = cloneTree(root->children[i]);
		ret->children.push_back(child);
	}
	return ret;
}