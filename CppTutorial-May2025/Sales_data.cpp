#include "Sales_data.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;

void testSalesDataMemory() {
	Sales_data data, *p;

	cout << "Sizeof Sales_data " << sizeof(Sales_data);

	cout << "Sizeof data " << sizeof(data);
	
	cout << "Sizeof sum of comps of data " << " bookNo:: " << sizeof(data.bookNo) << " revenue:: " << sizeof(data.revenue) << " units sold:: " << sizeof(data.units_sold)
		<< "sum :: " << sizeof(data.bookNo) + sizeof(data.revenue) + sizeof(data.units_sold) << endl;
	cout << "Sizeof p " << sizeof(p);
	cout << "Sizeof *p " << sizeof(*p);
	cout << "Sizeof data.revenue " << sizeof(data.revenue);
}