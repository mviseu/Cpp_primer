#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iostream>

int main() {
	std::vector<std::string> vec = {"How", "", "many", "", "empty", "strings"};
	std::cout << std::count_if(vec.cbegin(), vec.cend(), std::mem_fn(&std::string::empty)) << std::endl;
	return 0;
}