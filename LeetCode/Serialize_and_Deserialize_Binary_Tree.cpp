//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
//Design an algorithm to serialize and deserialize a binary tree.There is no restriction on how your serialization / deserialization algorithm should work.You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//For example, you may serialize the following tree
//1
/// \
//2   3
/// \
//4   5
//
//as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree.You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//
//Note: Do not use class member / global / static variables to store states.Your serialize and deserialize algorithms should be stateless.

#include <string>
#include <sstream>
#include "TreeNode.h"

using namespace std;

class Codec
{
public:
	void serializeSubTree(TreeNode *pNode, ostringstream &out)
	{
		if (pNode)
		{
			out << pNode->val << " ";
			serializeSubTree(pNode->left, out);
			serializeSubTree(pNode->right, out);
		}
		else
			out << "# ";
	}

	TreeNode* deserializeSubTree(istringstream &in)
	{
		string temp;
		in >> temp;
		if (temp == "#")
			return 0;
		int val = stoi(temp);
		TreeNode *pNode = new TreeNode(val);
		pNode->left = deserializeSubTree(in);
		pNode->right = deserializeSubTree(in);
		return pNode;
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		ostringstream out;
		serializeSubTree(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		istringstream in(data);
		TreeNode *root = deserializeSubTree(in);
		return root;
	}
};

void testCodec()
{
	Codec c;
	TreeNode *root = new TreeNode(1);
	TreeNode *pNode = c.deserialize(c.serialize(root));
}