#include <iostream>
#include <vector>

#include "passing_arrays_to_functions.h"

using namespace std;

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
		cout << "i[" << i << "]" << " " << arr[i] << endl;
	}
}

void passAnArrayPointer(int* pArr, int size)
{	
	for (int i = 0; i < size; i++)
	{
		cout << i << " :" <<  *(pArr++) << endl;
	}
}


/// <summary>
///inserts into vector so at some point the vector is coppied in another 
/// memory location with increased capacity
/// </summary>
void testing_vector() {
	std::vector<int> vec;
	std::vector<int*> memoryAddresses;

	std::cout << "Initial capacity: " << vec.capacity() << endl;
	memoryAddresses.push_back(&vec[0]);

	for (int j = 1; j < 10; ++j) {
		for (int i = 0; i < 100; ++i) {
			vec.push_back(i);
		}
		memoryAddresses.push_back(&vec[0]);
	}

	for (int i = 0; i < memoryAddresses.size(); i++)
	{
		cout << "Memory address of vector: " << memoryAddresses[i] << endl;
	}
}