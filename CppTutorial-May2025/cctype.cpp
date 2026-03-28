#include <string>
#include <ranges>
#include <iostream>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;

void ccTypeWithRanges() {
	string s("Hello World!!");

	decltype(s.size()) punct_cnt = 0;

	char punctuations[3] = { '!', '.', '?' };

	auto isPunct = [](char c) {
		return c == '!' || c == '.' || c == '?';
	};

	auto punct_count = std::ranges::count_if(s, isPunct);

	cout << "Punctuation = " << punct_count << endl;
}