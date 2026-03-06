#include <string>
#include <iostream>
#include <vector>
using std::cout; using std::endl;

struct MyStruct
{
	std::string name;
	
	MyStruct() {
		cout << "default constructor\n";
	}

	MyStruct(const MyStruct& other) : name(other.name) {
		cout << "copy constructor\n";
	}

	MyStruct(MyStruct&& other) noexcept : name(std::move(other.name)) {
		cout << "move constructor\n";
	}
};

void copyConstructor(MyStruct c)
{

}

void testConstructor(MyStruct&& c)
{
	MyStruct asd(std::move(c));
}

void testMoveCopyDefaultConstructors() {

	std::vector<MyStruct> vec;
	vec.reserve(10);

	MyStruct a;
	a.name = "asd";
	//testConstructor(std::move(a));
	//testConstructor(std::move(a));

	//MyStruct b = a;//copy constructor
	//MyStruct c(a);//copy constructor
	MyStruct&& rref = std::move(a);
	copyConstructor(rref);
	testConstructor(std::move(rref));
	
	//vec.push_back(a);
	//vec.push_back(std::move(a));

	//vec.emplace_back(a);
	//vec.emplace_back(std::move(a));
}