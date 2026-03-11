#include <iostream>
#include <vector>

#include "passing_arrays_to_functions.h"

using namespace std;

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

void passBySizedArray(int arr[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << i << " " << arr[i] << endl;
	}
}

void passUnsizedArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "i[" << i << "]" << " " << arr[i] << " ";
	}

	cout << endl;

	//this is wrong because of scale up to size
	for (int i = 0; i < size; i++)
	{
		cout << "i[" << i << "]" << " " << *(arr + (i * sizeof(int)));
	}

	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "i[" << i << "]" << " " << *(arr + i) << endl;
	}
}

void passAnArrayPointer(int* pArr, int size)
{	
	for (int i = 0; i < size; i++)
	{
		cout << i << " :" <<  *pArr++ << endl;
	}

}

void testing_vector() {
	std::vector<int> vec;
	std::vector<int*> memoryAddresses;

	std::cout << "Initial capacity: " << vec.capacity() << endl;
	vec.push_back(0);
	memoryAddresses.push_back(&vec[0]);

	for (int j = 1; j < 10; ++j) {
		for (int i = 0; i < 100; ++i) {
			vec.push_back(i);
		}
		memoryAddresses.push_back(&vec[0]);
	}
	cout << endl;
	for (int i = 0; i < memoryAddresses.size(); i++)
	{
		cout << "Memory address of vector: " << memoryAddresses[i] << " ";
	}
}