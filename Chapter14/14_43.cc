#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
	int i = 12;
	std::vector<int> vec = {2, 11, 13};
	auto mod_i = std::bind(std::modulus<int>(), i, std::placeholders::_1);
	auto is_i_mod_0 = std::bind(std::equal_to<int>(), 0, mod_i);
	std::cout << std::any_of(vec.cbegin(), vec.cend(), is_i_mod_0) << std::endl;
	return 0;
}

