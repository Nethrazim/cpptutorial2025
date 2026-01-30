#include <iterator>
using std::begin; using std::end;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;


void testMultiDimensionArrays()
{
	//uninitialized ints
	int ia1[3][4];

	ia1[0][0] += ia1[1][1];

	std::cout <<"Uninitialized multi dimensional array " << ia1[0][0] << std::endl;

	int arr[20][20][30] = { 0 };

	ia1[2][3] = arr[0][0][0];

	int (&row)[4] = ia1[1];
	std:cout << row[1] << std::endl;


	int ia2[3][4] = {
		{ 0, 1, 2 ,3 },
		{ 4, 5, 6, 7 },
		{ 8, 9, 10, 11 }
	};

	int ia3[3][4] = { 0, 1, 2 , 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	
	int ia4[3][4] = { {0}, { 4 }, {8} };

	int ix[3][4] = { 0, 3, 6, 9 };

	cout << ix[0][3] << ' ' << ix[1][0] << ix[2][0] << endl;

	constexpr size_t rowCnt = 3, colCnt = 4;

	const size_t rowCnt2 = 3, colCnt2 = 4; 

	int ex1[rowCnt][colCnt];
	
	int ex2[rowCnt2][colCnt2];
	
	ex2[0][0] = 1;
}