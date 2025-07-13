#include "same_tree.h"


bool SameTreeSolution::IsSameTree(TreeNode *p, TreeNode *q, bool *resultPtr = nullptr)
{
	bool *result = new bool();
	
	if (p->val != q->val)
	{
		*result = false;
		return false;
	}

	if (p->left != nullptr || q->left != nullptr)
	{
		IsSameTree(p->left != nullptr ? p->left : p, q->left != nullptr ? q->left : q, result);
	}


	if (p->right != nullptr || q->right != nullptr)
	{
		IsSameTree(p->right != nullptr ? p->right : p , q->right != nullptr ? q->right : q, result);
	}

	if (*result == false) {
		return false;
	}
	
	return true;
}
