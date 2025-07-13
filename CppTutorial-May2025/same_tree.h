#pragma once
struct TreeNode {
	int val;
	TreeNode* right;
	TreeNode* left;
	TreeNode() : val(0), right(nullptr), left(nullptr) {}
	TreeNode(int val) : val(val), right(nullptr), left(nullptr) {}
	TreeNode(int val, TreeNode* left) : val(val), left(left), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};


class SameTreeSolution
{
public:
	bool IsSameTree(TreeNode* p, TreeNode* q, bool *result);
};