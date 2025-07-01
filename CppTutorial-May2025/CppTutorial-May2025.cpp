// CppTutorial-May2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <tuple>

#include "value_switch.h"
#include "copy_by_value_vs_copy_by_reference.h"
#include "passing_arrays_to_functions.h"
#include "linked_list_custom.h"
#include "merge_ranges.h";
#include "plus_one.h"
#include "pascal_triangle.h"

using namespace std;


int main()
{
	//int arr [] = { 1, 2, 3, 4, 5 };
	//passBySizedArray(arr);
	//passAnArrayPointer(&arr[0], 5);
	//testing_vector();

	//Node *head = populateLinkedList(10);
	//printLinkedList(head);
	/*std::vector<tuple<int, int>> aRange = {
		{7, 11},
		{13,15},
		{15,16},
		{17,19},
		{3,5},
		{5,7},
	};*/

	//printRange(mergeRanges(aRange));

	//std::vector<int> listOfInts = { 1,2,3,4,5 };
	//plusOne(listOfInts);

	generate(5);
}
	
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
