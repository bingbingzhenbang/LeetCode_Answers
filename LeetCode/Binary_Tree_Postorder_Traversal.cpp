//Given a binary tree, return the postorder traversal of its nodes' values.
//
//For example :
//Given binary tree{ 1, #, 2, 3 },
//
//1
//\
//2
///
//3
//
//
//
//return[3, 2, 1].
//
//Note: Recursive solution is trivial, could you do it iteratively ?

#include "TreeNode.h"
#include <vector>
#include <utility>
#include <stack>

using namespace std;

vector<int> postorderTraversal(TreeNode* root)
{
	if (root == 0)
		return vector<int>();
	vector<int> result;
	stack< pair<int, TreeNode*> > nodeStack;
	nodeStack.push(pair<int, TreeNode*>(0, root));
	while (!nodeStack.empty())
	{
		pair<int, TreeNode*> &top_pair = nodeStack.top();
		int visited = top_pair.first;
		TreeNode *pNode = top_pair.second;
		switch (visited)
		{
		case 0:// no subtree visited
		    {
				   if (pNode->right)
					   nodeStack.push(pair<int, TreeNode*>(0, pNode->right));
				   if (pNode->left)
					   nodeStack.push(pair<int, TreeNode*>(0, pNode->left));
				   else
					   top_pair.first = 1;
		    }
			break;
		case 1:// left subtree visited
		    {
				   if (pNode->right == 0)
					   top_pair.first = 2;
		    }
			break;
		case 2:// both subtrees visited
		    {
				   result.push_back(pNode->val);
				   nodeStack.pop();
				   if (!nodeStack.empty())
				   {
					   pair<int, TreeNode*> &second_top = nodeStack.top();
					   TreeNode *secondNode = second_top.second;
					   if (secondNode->left == pNode)
					   {
						   second_top.first = 1;
					   }
					   else if (secondNode->right == pNode)
					   {
						   second_top.first = 2;
					   }
				   }
		    }
			break;
		default:
			break;
		}
	}
	return result;
}

vector<int> postorderTraversal2(TreeNode* root)
{
	if (root == 0)
		return vector<int>();
	vector<int> result;
	stack< pair<int, TreeNode*> > nodeStack;
	TreeNode *p = root;
	do
	{
		while (p)
		{
			nodeStack.push(pair<int, TreeNode*>(0, p));
			p = p->left;
		}
		int flag = 1;
		while (flag && !nodeStack.empty())
		{
			pair<int, TreeNode*> &top_pair = nodeStack.top();
			switch (top_pair.first)
			{
			case 0:
			    {
					  top_pair.first = 1;
					  p = top_pair.second->right;
					  flag = 0;
			    }
				break;
			case 1:
			    {
					  result.push_back(top_pair.second->val);
					  nodeStack.pop();
			    }
				break;
			default:
				break;
			}
		}
	} while (!nodeStack.empty());
	return result;
}

void testPostorderTraversal()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	vector<int> rt = postorderTraversal(root);
}