#pragma once
#include <iostream>

class DebugDelete {
public:
	DebugDelete(std::ostream &out = std::cerr) : os(out) {}
	template <typename T> void operator()(T * ptr) const {
		std::cout << "Deleting pointer with DebugDelete" << std::endl;
		delete ptr;
	} 

private:
	std::ostream &os;
};
