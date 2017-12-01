#include "16_28_SharedPtr.h"
#include <iostream>
#include <memory>
#include <string>


int main() {
	SharedPtr<int> sptr(new int(2));
	SharedPtr<std::string> ptr_default;
	return 0;
}