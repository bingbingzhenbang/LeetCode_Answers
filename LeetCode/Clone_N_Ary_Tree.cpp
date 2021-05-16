#include <vector>

using namespace std;

namespace {
	class Node {
	public:
		int val;
		vector<Node*> children;

		Node() {}

		Node(int _val) {
			val = _val;
		}

		Node(int _val, vector<Node*> _children) {
			val = _val;
			children = _children;
		}
	};

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
}