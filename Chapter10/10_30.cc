#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::istream_iterator<int> iter_in(std::cin), eof;
	std::vector<int> vec(iter_in, eof);
	std::sort(vec.begin(), vec.end());
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;
	return 0;
}