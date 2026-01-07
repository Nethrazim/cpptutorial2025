#include "for_ex.h"
#include <iostream>

void for_ex() 
{
	int sum = 0;

	for (int i = -100; i <= 100; ++i) {
		sum += i;
	}

	std::cout << sum << std::endl;
}