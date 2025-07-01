#include <iostream>
#include "copy_by_value_vs_copy_by_reference.h"

using namespace std;

void execCopyByValue(int a);
void execCopyByReference(int* p);

//dangling reference
int& returnByReferenceOutOfScope()
{
	int a = 1;
	std::cout << &a << std::endl;
	return a;
}

void testCopyByValue()
{
	int asd = 30;

	execCopyByValue(asd);

	cout << asd << endl;
}

void testCopyByReference()
{
	int a = 2;
	int *pAsd = new int(2);
	
	std::cout << pAsd << *pAsd << endl;

	execCopyByReference(pAsd);
}

void execCopyByReference(int *p)
{
	cout << p << *p << endl;
}

void execCopyByValue(int a)
{
	a++;

	cout << "Inside " << a << endl;
}