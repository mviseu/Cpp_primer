#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

class StringBound {

public:
	StringBound(std::size_t lwr, std::size_t upr) : lower_bound(lwr), upper_bound(upr) {};
	bool operator() (std::string str) const {
		return str.size() <= upper_bound && str.size() >= lower_bound;
	}

private:
	std::size_t lower_bound;
	std::size_t upper_bound;
};

int main() {
	std::ifstream in("testfile");
	std::istream_iterator<std::string>in_iter(in), eof_iterator;
	std::vector<std::string> vec(in_iter, eof_iterator);
	auto ct = std::count_if(vec.cbegin(), vec.cend(), StringBound(1, 9));
	std::cout << "1 through 9: " << ct << std::endl;
	ct = std::count_if(vec.cbegin(), vec.cend(), StringBound(10, -1));
	std::cout << "10 or more: " << ct << std::endl;
	return 0;
}