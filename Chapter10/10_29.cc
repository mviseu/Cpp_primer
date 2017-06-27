//read a file into vector of strings using istream_iterator
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>
#include <algorithm>

int main() {
	std::ifstream input("infile");
	if(!input.good()) {
		return -1;
	}
	std::istream_iterator<std::string> iter_in(input), eof;
	std::ostream_iterator<std::string> iter_out(std::cout, " ");
	std::vector<std::string> vec(iter_in, eof);
	std::copy(vec.cbegin(), vec.cend(), iter_out);

	return 0;

}
