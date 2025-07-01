#include <vector>
#include <iostream>

std::vector<int> plusOne(std::vector<int>& digits)
{

	int acc = 0;
	for (int i = 0; i < digits.size(); i++)
	{
		acc += digits[i] * pow(10, (digits.size() - 1) - i);
	}

	acc++;

	std::cout << acc << std::endl;


	std::vector<int> result;


	while (acc > 0)
	{
		result.push_back(acc % 10);
		acc = acc / 10;
	}

	std::reverse(result.begin(), result.end());

	return result;
}

