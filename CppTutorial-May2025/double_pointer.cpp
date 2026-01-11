#include <iostream>


void testDoublePointer()
{
	int asd = 12;
	int* pAsd = &asd;
	int** dpAsd = &pAsd;
	int*** tpAsd = &dpAsd;
	int**** qpAsd = &tpAsd;

	std::cout << asd << " " << pAsd << " " << dpAsd << " " << tpAsd << " " << qpAsd << std::endl;
	std::cout << &asd << " " << &pAsd << " " << &dpAsd << " " << &tpAsd << " " << &qpAsd << std::endl;
	std::cout << asd << " " << *pAsd << " " << **dpAsd << " " << ***tpAsd << " " << ****qpAsd << std::endl;

	
	int ival = 1024;
	int* pi = &ival;
	int** ppi = &pi;

	std::cout << "The value of ival\n"
		<< "direct value: " << ival << "\n"
		<< "indirect value: " << *pi << "\n"
		<< "doubly indirect value: " << **ppi << "\n"
		<< std::endl;

	int i = 2;
	int* pl = &i;
	*pl = *pl * *pl;
	std::cout << "i = " << std::endl;

	*pl *= *pl;
	std::cout << "i = " << std::endl;
}