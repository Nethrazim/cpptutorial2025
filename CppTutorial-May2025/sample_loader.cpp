#include <iostream>

#include "sample_loader.h"
#include "same_tree.h"

void StartLeetCodeSameTree();

void StartSample(LoadingState sample)
{
	switch (sample)
	{
		case LEET_CODE_SAME_TREE:
			StartLeetCodeSameTree();
		break;

	}
}

void StartLeetCodeSameTree()
{
	TreeNode *head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(1);

	TreeNode *head2 = new TreeNode(1);
	head2->left = new TreeNode(2);
	head2->right = new TreeNode(3);
	head2->left->left = new TreeNode(4);
	head2->left->right = new TreeNode(5);

	SameTreeSolution sameTreeSolution;
	std::cout << "Is Same Tree ? " << (sameTreeSolution.IsSameTree(head, head2, nullptr) == true ? "True" : "False") << std::endl;
}