#include <iostream>
#include "value_switch.h"

using namespace std;

void switchTwoVariableValues()
{
	int a = 2;
	int b = 3;

	cout << "Initial values" << endl;
	cout << "a = " << a << " b = " << b << endl;
	int aux;

	aux = a;
	a = b;
	b = aux;

	cout << "After switch values" << endl;
	cout << "a = " << a << " b = " << b << endl;
}