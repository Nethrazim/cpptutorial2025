#include <vector>
#include <iostream>

std::vector<std::vector<int>> generatePascalTriangle(int numRows)
{
	std::vector<std::vector<int>> pascalTriangle;

	for (int i = 1; i <= numRows; i++)
	{
		if (i == 1) {
			pascalTriangle.push_back({ 1 });
		}
		else if (i == 2) {
			pascalTriangle.push_back({ 1, 1 }); 
		}
		else {
			std::vector<int> row;
			row.push_back(1);
			for (int j = 0; j < pascalTriangle[i - 2].size() - 1; j++)
			{
				row.push_back(pascalTriangle[i - 2][j] + pascalTriangle[i - 2][j + 1]);
			}
			row.push_back(1);
			pascalTriangle.push_back(row);
		}
	}

	for (int i = 0; i < pascalTriangle.size(); i++)
	{
		for (int j = 0; j < pascalTriangle[i].size(); j++)
		{
			std::cout << pascalTriangle[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return pascalTriangle;
}