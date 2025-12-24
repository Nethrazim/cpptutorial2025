//AVL TREE
#include "node_structures.h"
#include <iostream>
using namespace std;

int height(AVLTreeNode* node)
{
	return node ? node->height : 0;
}

int max(int x, int y)
{
	return x > y ? x : y;
}

//     y          x
//   x 	 T3    T1  y
// T1 T2 		 T2 T3
					//

AVLTreeNode* rightRotate(AVLTreeNode* y)
{
	AVLTreeNode* x = y->left;
	AVLTreeNode* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = 1 + max(height(y->left), height(y->right));
	x->height = 1 + max(height(x->left), height(x->right));


	return x;
}

AVLTreeNode* leftRotate(AVLTreeNode* x)
{
	AVLTreeNode* y = x->right;
	AVLTreeNode* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = 1 + max(height(x->left), height(x->right));

	y->height = 1 + max(height(y->left), height(y->right));

	return y;
}

int getBalance(AVLTreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	return height(node->left) - height(node->right);
}

AVLTreeNode* insert(AVLTreeNode* node, int key) {

	if (node == nullptr)
		return new AVLTreeNode(key);

	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}
	else {
		return node;
	}

	node->height = 1 + max(height(node->left), height(node->right));
	
	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void avlPreOrder(AVLTreeNode* root)
{
	if (root != nullptr)
	{
		cout << "key= " << root->key << " " << "balance=" << getBalance(root) << endl;
		avlPreOrder(root->left);
		avlPreOrder(root->right);
	}
}
/*
    30
  20  40
19 21
*/
void testAvlInsert()
{
	AVLTreeNode* root = nullptr;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 70);
	root = insert(root, 20);

	avlPreOrder(root);
}