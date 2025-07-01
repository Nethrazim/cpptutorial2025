#include "merge_ranges.h"

#include <tuple>
#include <vector>
#include <algorithm>
#include <iostream>


std::vector<std::tuple<int, int>> mergeRanges(const std::vector<std::tuple<int, int>>& iRanges)
{
	std::vector<std::tuple<int, int>> result;
	std::vector<std::tuple<int, int>> ranges = iRanges;

	std::cout << "Initial Range" << std::endl;
	printRange(ranges);

	
	std::sort(ranges.begin(), ranges.end(), [](const auto& a, const auto& b) {
		return std::get<0>(a) < std::get<0>(b);
	});

	
	int i = 1; 
	
	std::tuple<int, int> current = ranges[0];


	while (i < ranges.size())
	{
		if (std::get<1>(current) >= std::get<0>(ranges[i]))
		{
			std::get<1>(current) = std::get<1>(ranges[i]);
		}
		else
		{
			result.push_back(current);
			current = ranges[i];
		}
		i++;
	}	
	
	result.push_back(current);

	std::cout << "sAfter Sorting" << std::endl;
	printRange(ranges);

	return result;
}

void printRange(const std::vector<std::tuple<int, int>>& ranges)
{
	for (int i = 0; i < ranges.size(); i++)
	{
		std::cout << "(" << std::get<0>(ranges[i]) << "," << std::get<1>(ranges[i]) << ")" << std::endl;
	}
}