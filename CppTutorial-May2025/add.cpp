#include <iostream>
#include "add.h"
#include "Sales_item.h"

namespace Chapter1
{
	void addTwoNumberKeyboard()
	{
		std::cout << "Enter two numbers: " << std::endl;
		int v1 = 0, v2 = 0;

		std::cin >> v1 >> v2;

		std::cout << "The sum of " << v1 << " and " << v2
			<< " is " << v1 + v2;
	}
}


void Chapter1::addTwoSaleItemsKeyboard()
{
	Sales_item item1, item2;

	std::cin >> item1 >> item2;

	std::cout << item1 + item2 << std::endl;
}

void Chapter1::checkSaleItemISBN()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;

	if (item1.isbn() == item2.isbn())
	{
		std::cout << item1 + item2 << std::endl;
		return;
	}
	else
	{
		std::cerr << "Data must relate to the same ISBN" << std::endl;
		return;
	}
}