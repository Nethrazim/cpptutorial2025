#include "node_structures.h"
#include <iostream>
#include <queue>

int calculateTreeSize(TreeNodeV2* node);

void inorder(TreeNodeV2* node);
void preorder(TreeNodeV2* node);
void postorder(TreeNodeV2* node);
void levelorder(TreeNodeV2* node);

	//2
	//1 3
  //6 7 4 5

void testCalculateTreeSize()
{
	TreeNodeV2* head = new TreeNodeV2(2);
	head->left = new TreeNodeV2(1);
	head->right = new TreeNodeV2(3);

	head->right->left = new TreeNodeV2(4);
	head->right->right = new TreeNodeV2(5);

	head->left->left = new TreeNodeV2(6);
	head->left->right = new TreeNodeV2(7);

	std::cout << "Tree Size: " << calculateTreeSize(head) << std::endl;
}


void testTraverseTreeInOrder()
{
	TreeNodeV2* head = new TreeNodeV2(2);
	head->left = new TreeNodeV2(1);
	head->right = new TreeNodeV2(3);

	head->right->left = new TreeNodeV2(4);
	head->right->right = new TreeNodeV2(5);

	head->left->left = new TreeNodeV2(6);
	head->left->right = new TreeNodeV2(7);

	inorder(head);
}

void testTraverseTreePreOrder()
{
	TreeNodeV2* head = new TreeNodeV2(2);
	head->left = new TreeNodeV2(1);
	head->right = new TreeNodeV2(3);

	head->right->left = new TreeNodeV2(4);
	head->right->right = new TreeNodeV2(5);

	head->left->left = new TreeNodeV2(6);
	head->left->right = new TreeNodeV2(7);

	preorder(head);
}

void testTraverseTreePostOrder()
{
	TreeNodeV2* head = new TreeNodeV2(2);
	head->left = new TreeNodeV2(1);
	head->right = new TreeNodeV2(3);

	head->right->left = new TreeNodeV2(4);
	head->right->right = new TreeNodeV2(5);

	head->left->left = new TreeNodeV2(6);
	head->left->right = new TreeNodeV2(7);

	postorder(head);
}

void testTraverseTreeLevelOrder()
{
	TreeNodeV2* head = new TreeNodeV2(2);
	head->left = new TreeNodeV2(1);
	head->right = new TreeNodeV2(3);

	head->right->left = new TreeNodeV2(4);
	head->right->right = new TreeNodeV2(5);

	head->left->left = new TreeNodeV2(6);
	head->left->right = new TreeNodeV2(7);

	levelorder(head);
}

int calculateTreeSize(TreeNodeV2* node)
{
	static int size = 0;

	if (!node)
	{
		return size;
	}
	else
	{
		std::cout << "Node.value:" << node->value << std::endl;
		size++;
		calculateTreeSize(node->left);
		calculateTreeSize(node->right);
		return size;
	}
}

void inorder(TreeNodeV2* node)
{
	if (!node)
	{
		return;
	}
	else
	{
		inorder(node->left);
		std::cout << "Node.value:" << node->value << std::endl;
		inorder(node->right);
	}
}

void preorder(TreeNodeV2* node)
{
	if (!node) return;

	std::cout << "Node.value:" << node->value << std::endl;
	preorder(node->left);
	preorder(node->right);
}

void postorder(TreeNodeV2* node)
{
	if (!node) return;
	postorder(node->left);
	postorder(node->right);
	std::cout << "Node.value:" << node->value << std::endl;
}

void levelorder(TreeNodeV2* node)
{
	if (!node) return;

	std::queue<TreeNodeV2*> queue;

	queue.push(node);

	while (!queue.empty())
	{
		TreeNodeV2* current = queue.front();
		queue.pop();
		std::cout << "Node.value:" << current->value << std::endl;

		current->left ? queue.push(current->left) : void();
		current->right ? queue.push(current->right) : void();
	}
}