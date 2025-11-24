#include "binary_search_tree.h"
#include <iostream>

#include "node_structures.h"
#include "simple_tree.h"

int findMinimumValueInBSTV1(TreeNodeV2* node);
TreeNodeV2* insertInBST(TreeNodeV2* root, int value);
void insertInBSTV2(TreeNodeV2*& root, int value);
    //6
  //5 7
//3 6 6 8

void testFindMinimumValueInBST()
{
	TreeNodeV2* head = new TreeNodeV2(6);
	head->left = new TreeNodeV2(5);
	head->right = new TreeNodeV2(7);

	head->right->left = new TreeNodeV2(6);
	head->right->right = new TreeNodeV2(8);

	head->left->left = new TreeNodeV2(3);
	head->left->right = new TreeNodeV2(6);

	std::cout << "Minimum Value: " << findMinimumValueInBSTV1(head) << std::endl;
}

void testInsertInBST()
{
	TreeNodeV2* root = new TreeNodeV2(22);
	int valuesToInsert[] = { 12, 30, 8, 20, 30 };

	for (int i = 0;  i < sizeof(valuesToInsert) / sizeof(int); ++i)
	{
		insertInBST(root, valuesToInsert[i]);
	}

	levelorder(root);
}

void testInsertInBSTV2()
{
	TreeNodeV2* root = new TreeNodeV2(22);
	int valuesToInsert[] = { 12, 30, 8, 20, 30 };

	for (int i = 0; i < sizeof(valuesToInsert) / sizeof(int); ++i)
	{
		insertInBSTV2(root, valuesToInsert[i]);
	}

	levelorder(root);
}

int findMinimumValueInBSTV1(TreeNodeV2* node)
{
	if (!node->left)
	{
		return node->value;
	}

	return findMinimumValueInBSTV1(node->left);
}


TreeNodeV2* insertInBST(TreeNodeV2* root, int value)
{
	if (root == nullptr)
	{
		return new TreeNodeV2(value);
	}

	if (value < root->value)
	{
		root->left = insertInBST(root->left, value);
	}

	if (value >= root->value)
	{
		root->right = insertInBST(root->right, value);
	}

	return root;
}

void insertInBSTV2(TreeNodeV2*& root, int value)
{
	if (root == nullptr)
	{
		root = new TreeNodeV2(value);
		return;
	}

	if (value < root->value)
	{
		insertInBSTV2(root->left, value);
	}

	if (value >= root->value)
	{
		insertInBSTV2(root->right, value);
	}
	
}