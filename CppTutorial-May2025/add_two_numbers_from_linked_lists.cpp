#include "add_two_numbers_from_linked_lists.h"
#include <math.h>
#include <iostream>

using namespace std;

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int idx = -1;

	int number1 = 0;
	std::cout << parseNumberFromList(l1, number1, idx) << std::endl;
	
	idx = -1;
	int number2 = 0;
	parseNumberFromList(l2, number2, idx);
		
	int sum = number1 + number2;
	
	std::cout << sum << std::endl;

	return new ListNode();
}

ListNode* Solution::generateLinkedListFromArray(int arr[], int size)
{
	int sizeOfArr = size / sizeof(int);

	ListNode* firstNode = new ListNode(arr[0]);
	ListNode* head = firstNode;

	for (int i = 1; i < sizeOfArr; i++)
	{
		firstNode->next = new ListNode(arr[i]);
		firstNode = firstNode->next;
	}

	return head;
}


int Solution::parseNumberFromList(ListNode* list, int& result, int& idx)
{
	idx++;
	int localIdx = idx;

	if (list->next != nullptr)
	{
		parseNumberFromList(list->next, result, idx);
	}

	result += pow(10, localIdx) * list->val;
	
	return result;
}