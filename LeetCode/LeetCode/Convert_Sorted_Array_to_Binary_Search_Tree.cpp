//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

#include "TreeNode.h"
#include <vector>

using namespace std;

TreeNode* sortedArrayToSubBST(vector<int>& nums, int start, int last)
{
	if (start >= last)
		return 0;
	if (start + 1 == last)
		return new TreeNode(nums[start]);
	int mid = (start + last) / 2;
	TreeNode *midNode = new TreeNode(nums[mid]);
	midNode->left = sortedArrayToSubBST(nums, start, mid);
	midNode->right = sortedArrayToSubBST(nums, mid + 1, last);
	return midNode;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	int size = nums.size();
	if (size == 0)
		return 0;
	return sortedArrayToSubBST(nums, 0, size);
}