#include <iostream>

void testDeclarations() {
	int a = 0;
	decltype(a) b = 2; // type of a so b is int
	decltype(a) c = b; // same 
	decltype(a) d = a; // same

	decltype((a)) e = a; //reference to a; int &a;

	++e;

	std::cout << e << " " << a << "\n";
}