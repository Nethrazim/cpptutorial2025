#include <iostream>
#include <vector>
#include <algorithm>

//smallest is considered 1 
void testFirstMissingPositive()
{
	//std::vector<int> nums = { 1,2,0 }; //13
	//
	std::vector<int> nums = { 3, 4, -1, 1 };
	// - 1 1 3 4 
	//           3 
	std::sort(nums.begin(), nums.end());

	int minimum = 1;
	bool isFound = false;
	for (int k = 0; k < nums.size(); ++k)
	{
		if (nums[k] >= 1)
		{
			if (nums[k] - minimum >= 1) {
				isFound = true;
				std::cout << minimum << std::endl;
				break;
			}
			else if(nums[k] - minimum == 0)
			{
				minimum++;
			}	
		}
	}

	if (!isFound && nums[nums.size() - 1] >= 1) {
		std::cout << ++nums[nums.size() - 1] << std::endl;
	}
	else
		std::cout << 1 << std::endl;
	
}