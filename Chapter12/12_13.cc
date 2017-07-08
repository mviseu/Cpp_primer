#include <memory>
#include <iostream>

int main() {
	auto sp = std::make_shared<int>();
	auto p = sp.get();
	std::cout << *p << std::endl;
	//run time error -> double free and corruption of free store...
	//delete p;
	return 0;
}