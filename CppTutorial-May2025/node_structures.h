#pragma once


struct TreeNodeV2
{
	int value;
	TreeNodeV2* left;
	TreeNodeV2* right;
};


struct AVLTreeNode
{
	int key;
	AVLTreeNode* left;
	AVLTreeNode* right;
	int height;

	AVLTreeNode(int k)
	{
		key = k;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};
