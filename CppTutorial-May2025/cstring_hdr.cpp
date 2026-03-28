#include <string>
#include <iostream>
using std::string;
using std::cout; using std::endl;

int myStrLength(const char* c) {
	int length = 0;
	while (*c != '\0')
	{
		length++;
		c++;
	}


	return length;
}

void cstringHdr() {
	string s1 = "A string example";
	string s2 = "A different string";

	if (s1 < s2) {
		cout << s1 << endl;
	}
	else {
		cout << s2 << endl;
	}

	const char ca1[] = "A string example";
	const char ca2[] = "A different string";

	if (strcmp(ca1, ca2) < 0) {
		cout << ca1 << endl;
	}
	else
	{
		cout << ca2 << endl;
	}

	const char* cp1 = ca1, * cp2 = ca2;

	cout << strcmp(cp1, cp2) << endl;
	cout << strcmp(cp2, cp1) << endl;
	cout << strcmp(cp1, cp1) << endl;

	cout << strlen(cp1) << endl;
	cout << myStrLength(ca1) << endl;
	//hm how about writing a function to count the length
}