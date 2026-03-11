#include <iostream>
#include <array>
#include <malloc.h>

using std::cout; using std::endl;

void testDeclArrays() {
	int arr[] = { 1, 2, 3, 4, 5 };
	cout << "Arr.length = " 
		<< sizeof(arr) / sizeof(int)  << " " 
		<< sizeof(arr) << " "
		<< sizeof(arr) / sizeof(arr[0]) 
		<< endl;

	char cArr[5] = {};
	cout << "Arr.length = " << sizeof(cArr) / sizeof(char) << endl;
	
	//C++17
	cout << std::size(arr) << endl;

	std::array<int, 5> stdArr = { 1, 2, 3, 4};//only use 4 values for initializer to check with for()
	size_t length = stdArr.size(); //.size() works with std::array
	
	for (int val : stdArr)
	{
		cout << val << " ";
	}

	int* dynArr = new int[5];
	cout << sizeof(dynArr) << endl; //returns pointer size NOT array size;

	//lets try, commenting this because its not good nullptr = 0x000000
	
	bool isCounting = true;
	size_t lengthDynArray = 0;
	while (isCounting)
	{
		if (dynArr == nullptr)
		{
			isCounting = false;
		}

		dynArr += 1;
		lengthDynArray++;
		break;
	}
	dynArr -= 1;
	delete dynArr;//dynArr pointer has lost initial address but i put back above

	cout << "Size of dynArr " << lengthDynArray << endl;
	
	dynArr = new int[5];

	size_t allocatedBytes = _msize(dynArr);
	size_t numElements = allocatedBytes / sizeof(*dynArr);
	
	//if you're lucky because allocator calculation might round up
	cout << "Sizeof dynArr = " << numElements << endl;
}