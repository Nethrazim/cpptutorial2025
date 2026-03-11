#include <iostream>
#include <array>

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
}