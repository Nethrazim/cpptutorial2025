#include <iostream>
using std::cout; using std::endl;
using std::cin;

#include <cstddef>
using std::size_t;

int ia[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void testArraySizeOf() {
	constexpr size_t sz = sizeof(ia) / sizeof(*ia);
	//const size_t sz = sizeof(ia) / sizeof(*ia);

	int arr[sz];

	cout << "ia size: " << sz << endl;
}

void testConstExpressionVsConst() {
	//compile time constant
	constexpr int compile_time = 42;

	//runtime constant
	int value;
	std::cin >> value;
	const int runtime_const = value;
}


void testIncr() {
	int i = 0, j;
	//cout << "i = " << i << "j = " << j << endl;
	//i += j;
	j = i++;
	cout << i << " " << j << endl;
	j = ++i;
	cout << i << " " << j << endl;
}