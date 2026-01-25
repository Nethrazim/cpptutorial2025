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