#include <iterator>
using std::begin; using std::end;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cin; using std::cout; using std::endl;

void testPointerTraversal()
{
	int ia[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int* p = ia;
	++p;

	int* e = &ia[10];
	for (int* b = ia; b != e; ++b)
	{
		cout << *b << " ";
	}
	cout << endl;
	
	const size_t sz = 10;
	int arr[sz];

	for (auto& n : arr)
	{
		cin >> n;
	}

	for (auto i : arr) 
	{
		cout << i << " ";
	}
	cout << endl;

	int* pbeg = begin(arr), * pend = end(arr);

	while (pbeg != pend) {
		cout << *pbeg << " " << endl;
		pbeg++;
	}
}

void testPointerWithOffset()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptrArr = arr;

	cout << "The Fifth Element is " << *(ptrArr + 4) << endl;
}


void testSizeOfArray() {
	int ia[] = { 1, 2, 3, 4, 5, 6 };
	constexpr size_t sz = sizeof(ia) / sizeof(*ia);
	cout << "ia size" << ia << endl;
}

void prefixPostFixIncrement()
{
	int i = 0, j;
	j = ++i;

	cout << i << " " << j << endl;

	j = i++;
	cout << i << " " << j << endl;
}