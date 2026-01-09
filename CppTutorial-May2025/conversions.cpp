#include <iostream>

void testConversion() {
	int i = 42;
	std::cout << i << std::endl;

	if (i) {
		i = 0;
	}

	std::cout << i << std::endl;

	bool b = 42;
	std::cout << b << std::endl;

	int j = b;
	std::cout << j << std::endl;

	double pi = 3.14;
	std::cout << pi << std::endl;

	j = pi;
	std::cout << j << std::endl;

	unsigned char c = -1;
	i = c;
	std::cout << i << std::endl;

	for (int i = c; i >= 0; --i)
	{
		int val = --c;
		std::cout << val << std::endl;
	}
}