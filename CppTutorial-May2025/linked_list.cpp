#include <iostream>
#include "linked_list_custom.h"

struct Node
{
	int value;
	Node* pNext;
};


Node* populateLinkedList(int headValue)
{
	Node* pHead = new Node{ headValue, nullptr };

	Node* pNext = pHead;

	for (int i = 0; i < 10; i++)
	{
		Node* pNewNode = new Node{ i, nullptr };
		pNext->pNext = pNewNode;

		pNext = pNewNode;
	}

	return pHead;
};

void printLinkedList(Node* header)
{
	Node* pCurrent = header;

	while (pCurrent != nullptr)
	{
		std::cout << "Node value: " << pCurrent->value << std::endl;
		pCurrent = pCurrent->pNext;
	}
}