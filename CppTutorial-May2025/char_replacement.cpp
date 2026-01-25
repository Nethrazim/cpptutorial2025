#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;



void testMultipleCharReplacementTechniques() {
	string str("some string"), orig = str;
	
	if (!str.empty()) {
		cout << str[0] << endl;
	}

	if (!str.empty()) {
		str[0] = toupper(str[0]);
	}
	cout << str << endl;

	str = orig;

	if (str.begin() != str.end()) {
		auto it = str.begin();
		*it = toupper(*it);
	}
	cout << str << endl;

	str = orig;

	for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index)
	{
		str[index] = toupper(str[index]);
	}
	cout << str << endl;
	str = orig;

	for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
	{
		*it = toupper(*it);
	}
	cout << str << endl;
	str = orig;
}


void testCharComparison() {
	string s1 = "A string example";
	string s2 = "A different thing";

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
	else {
		cout << ca2 << endl;
	}
	
	const char* cp1 = ca1, * cp2 = ca2;
	//some extras
	int a[] = { 1, 2 };
	cout << "sizeof(a) " << sizeof(a) << endl;
	
	int* aPtr = a;
	cout << "sizeof(aPtr) " << sizeof(aPtr) << endl;
}