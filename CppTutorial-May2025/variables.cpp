#include <iostream>

int a_variables_not_initizalized;

extern int counter;

void test_a_variable_not_initialized()
{
	std::cout << "When global variable not initialized default is 0 :" << a_variables_not_initizalized << std::endl;
	
	//int age; //compile time error
	int age = 36;

	std::cout << "Local variable not initialized:" << age << std::endl;
	
	std::cout << "Declared and defined later: " << counter << std::endl;
}


int counter;


void testLocalVsGlobalVariable()
{
	static int x = 13;
	x++;

	int counter = 10;

	std::cout << counter << std::endl;
}


void testScopeVariables()
{
	static int x;
	x++;
	if (x > 11)
		return;
	testScopeVariables();
	
	
	
	int counter = 10;
	{
		int counter = 20;
		{
			int counter = 30;

			std::cout << counter << std::endl;
		}
	}

	long long asd = 20;
	std::cout << "long long size " << sizeof(asd) << std::endl;

	long long population = 7900000000LL;

	bool isRunning = false;

	std::cout << "sizeof bool " << sizeof(isRunning) << std::endl;
	std::cout << "sizeof isRunning " << sizeof(bool) << std::endl;
}

//tests also surrounding memory of a variable
void testConstantVariables()
{
	const double d = 20;
	//d++;//compile time error
	
	const int asd = 10;
	int* pASD = (int*)&asd;
	
	std::cout << "Address of const ASD " << pASD << std::endl;
	
	int age = 36;
	int* pAge = &age;
	//(*(++pAge)) = 37;//Stack around the variables age was corrupted
	std::cout << "Value of pAge " << *pAge << std::endl;
	//pASD++;//Stack around the variable asd was corrupted
	(*pASD) = 11;

	//Trying to get rid of stack around corrupted
	int* pointerAGE = new int(36);

	std::cout << "Memory address of pointerAGE " << pointerAGE <<  " and value = " << *pointerAGE << std::endl;
	
	(*(++pointerAGE)) = 37;
	(*(--pointerAGE)) = 38;
	std::cout << "New memory address of pointerAGE " << pointerAGE << " and value = " << *pointerAGE << std::endl;

	
	std::cout << asd << std::endl;
	std::cout << "New address of pASD : " << pASD << std::endl;
}

int& testDanglingReferences()
{
	int x = 10;
	return x; //BAD x is destroyed after stack pop
}

void testVariableInitializationMethods()
{
	int V1 = 42.3;
	int v2 = { 42 };
	//int v3 = { 42.3 };//this is a narrowin conversion error
}