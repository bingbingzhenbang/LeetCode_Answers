#include "TreeNode.h"

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
	if (original == nullptr || cloned == nullptr)
		return nullptr;
	if (cloned->val == target->val)
		return cloned;
	TreeNode *lret = getTargetCopy(original->left, cloned->left, target);
	if (lret != nullptr)
		return lret;
	TreeNode *rret = getTargetCopy(original->right, cloned->right, target);
	return rret;
}