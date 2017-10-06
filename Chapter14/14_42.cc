#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>

int main() {
	std::vector<int> vec = {1026, 1000, 1089, 1024, 1026};
	std::cout << std::count_if(vec.cbegin(), vec.cend(), std::bind(std::greater<int>(), std::placeholders::_1, 1024)) << std::endl;
	std::vector<std::string> vec_str = {"pooh", "pooh", "hello", "goodbye"};
	auto str_it = std::find_if(vec_str.cbegin(), vec_str.cend(), std::bind(std::not_equal_to<std::string>(), std::placeholders::_1, "pooh"));
	std::cout << *str_it << std::endl;
	std::transform(vec.begin(), vec.end(), vec.begin(), std::bind(std::multiplies<int>(), 2, std::placeholders::_1));
	std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}
