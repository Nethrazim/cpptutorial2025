#include <thread>
#include <chrono>
#include <iostream>
#include <tuple>

#include "sample_loader.h"
#include "sample_loader_includes.h"


//Forward declarations
void testPassBySizedArray();
void testPassUnsizedArray();
void testPassAnArrayPointer();
void testVector();

void testLeetCodeSameTree();
void testPrintLinkedList();
void testMergedRanges();
void testPlusOne();

void testAddTwoNumbersFromLinkedLists();
void testReturnByReferenceOutOfScope();
int& testDanglingReferences();
void testDanglingRefs();
void testPrintHexAndOctal();
void testFirstMissingPositive();

void StartSample(LoadingState sample)
{
	switch (sample)
	{
		case TEST_FIRST_MISSING_POSITIVE:
			testFirstMissingPositive();
			break;

		case TEST_UNARY_MINUS_ON_UNSIGNED:
			testPrintHexAndOctal();
			break;
		case TEST_VARIABLE_GLOBAL_VS_LOCAL:
			testLocalVsGlobalVariable();
			break;
		
		case TEST_VARIABLE_GLOBAL_UNINITIALIZED:
			test_a_variable_not_initialized();
			break;

		case TEST_VARIABLE_INITS:
			testVariableInitializationMethods();
			break;

		case TEST_SCOPE_VARIABLES:
			testScopeVariables();
			break;

		case TEST_CONSTANT_VARIABLES:
			testConstantVariables();
			break;

		case TEST_PASS_BY_SIZED_ARRAY:
			testPassBySizedArray();
			break;

		case TEST_PASS_BY_UNSIZED_ARRAY:
			testPassUnsizedArray();
			break;

		case TEST_PASS_BY_ARRAY_POINTER:
			testPassAnArrayPointer();
			break;

		case TEST_VECTOR:
			testVector();
			break;

		case TEST_LEET_CODE_SAME_TREE:
			testLeetCodeSameTree();
			break;

		case TEST_PRINT_LINKED_LIST:
			testPrintLinkedList();
			break;

		case TEST_MERGED_RANGES:
			testMergedRanges();
			break;

		case TEST_PLUS_ONE:
			testPlusOne();
			break;

		case TEST_ADD_TWO_NUMBERS_FROM_LINKED_LISTS:
			testAddTwoNumbersFromLinkedLists();
			break;

		case TEST_PASCAL_TRIANGLE:
			generatePascalTriangle(5);
			break;

		case TEST_RETURN_BY_REFERENCE_OUT_OF_SCOPE:
			testReturnByReferenceOutOfScope();
			break;

		case TEST_COPY_BY_VALUE:
			testCopyByValue();
			break;
		
		case TEST_COPY_BY_REFERENCE:
			testCopyByReference();
			break;

		case TEST_TREE_SIZE:
			testCalculateTreeSize();
			break;

		case TEST_TRAVERSE_TREE_IN_ORDER:
			testTraverseTreeInOrder();
			break;
		
		case TEST_TRAVERSE_TREE_PRE_ORDER:
			testTraverseTreePreOrder();
			break;
		
		case TEST_TRAVERSE_TREE_POST_ORDER:
			testTraverseTreePostOrder();
			break;

		case TEST_TRAVERSE_TREE_LEVEL_ORDER:
			testTraverseTreeLevelOrder();
			break;
		
		case TEST_FIND_MINIMUM_IN_BST:
			testFindMinimumValueInBST();
			break;

		case TEST_INSERT_IN_BST:
			testInsertInBST();
			break;

		case TEST_INSERT_IN_BST_V2:
			testInsertInBSTV2();
			break;
		
		case TEST_CALCULATE_MAXIMUM_DEPTH:
			testCalculateMaximumDepth();
			break;

		case TEST_AVL_INSERT:
			testAvlInsert();
			break;

		case TEST_DANGLING_REFERENCES:
			testDanglingRefs();
			break;

		case TEST_ADD_SALE_ITEMS:
			Chapter1::addTwoSaleItemsKeyboard();
			break;

		case TEST_SAME_ISBN_SALE_ITEMS:
			Chapter1::checkSaleItemISBN();
			break;

		case TEST_AVG_PRICE_SALE_ITEMS:
			Chapter1::avgPriceSaleItem();
			break;

		case TEST_FOR_EX:
			for_ex();
			break;
			
		case TEST_SIMPLE_THREADS:
			MultithreadindConcurrency::testSimpleThreads();
			break;

		case TEST_THREADS_WITH_MUTEX:
			MultithreadindConcurrency::testThreadsWithMutex();
			break;

		case TEST_THREADS_WITHOUT_MUTEX:
			MultithreadindConcurrency::testThreadsWithoutMutex();
			break;
		case TEST_THREADS_TAKING_TURNS:
			MultithreadindConcurrency::testThreadsTakingTurns();
			break;
		
		case TEST_FOR_COMPOUND_DECLARATIONS_POINTERS_REFERNCES:
			testCompoundDeclarations();
			break;

		case TEST_FOR_CONVERSIONS:
			testConversion();
			break;
		
		case TEST_FOR_DOUBLE_POINTERS:
			testDoublePointer();
			break;

		case TEST_DECLARATIONS:
			testDeclarations();
			break;

		case TEST_VECTOR_GRADES_FILLING:
			testVectorGrades();
			break;

		case TEST_DECLARATIONS_AND_STRING_MANIPULATIONS:
			testCDeclarationsAndStringManipulations();
			break;
	}
}

/* == == == == START tests passing_arrays_to_functions == == == ==*/

void testPassBySizedArray() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	passBySizedArray(arr);
}

void testPassUnsizedArray() {
	int arr[] = { 0, 1, 2, 3, 4, 5 };
	std::cout << "Size of array: " << sizeof(arr) << std::endl;
	int size = sizeof(arr) / sizeof(int);

	passUnsizedArray(arr, size);
}

void testPassAnArrayPointer() {
	int arr[] = { 21, 22, 23, 24, 25 };
	passAnArrayPointer(arr, sizeof(arr) / sizeof(int));
}

void testVector() {
	testing_vector();
}
/* == == == == END tests passing_arrays_to_functions == == == ==*/

 

void testLeetCodeSameTree() {
	TreeNode* head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(1);

	TreeNode* head2 = new TreeNode(1);
	head2->left = new TreeNode(2);
	head2->right = new TreeNode(3);
	head2->left->left = new TreeNode(4);
	head2->left->right = new TreeNode(5);

	bool isSameTree = IsSameTree(head, head2);

	std::cout << "Is Same Tree ? " << (isSameTree ? "True" : "False") << std::endl;
}

void testPrintLinkedList() {
	Node* head = populateLinkedList(10);
	printLinkedList(head);
}


void testMergedRanges() {
	std::vector<std::tuple<int, int>> aRange = {
		{7, 11},
		{13,15},
		{15,16},
		{17,19},
		{3,5},
		{5,7},
	};

	printRange(mergeRanges(aRange));
}


void testPlusOne() {
	std::vector<int> listOfInts = { 1,2,3,4,5 };
	plusOne(listOfInts);
}

void testAddTwoNumbersFromLinkedLists() {
	Solution addTwoNumbersSolution;

	int arr1[] = { 2,4,3 };
	ListNode* headOfList1 = addTwoNumbersSolution.generateLinkedListFromArray(arr1, sizeof(arr1));

	int arr2[] = { 5, 6, 4 };
	ListNode* headOfList2 = addTwoNumbersSolution.generateLinkedListFromArray(arr2, sizeof(arr2));

	addTwoNumbersSolution.addTwoNumbers(headOfList1, headOfList2);
}

void testPascalTriangle() {
	generatePascalTriangle(5);
}

void testReturnByReferenceOutOfScope() {
	int& ref = returnByReferenceOutOfScope();
	std::cout << ref << std::endl;
	std::cout << "At memory address " << &ref << " = " << ref << std::endl;
}

void testDanglingRefs() {
	int asd = 10;
	int& bsd = asd;
	
	bsd = 20;
	std::cout << asd << std::endl;

	int& c = testDanglingReferences();
	
	//Trying to make undefined behavior happen
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
	std::cout << "Dangling references C = " << c << std::endl;
}