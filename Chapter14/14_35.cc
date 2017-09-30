#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

class ReadLine {
public:
	std::string operator() (std::istream &is) const {
		std::string s;
		return (getline(is, s) ? s : std::string());
	}
};


int main() {
	ReadLine read_line;
	auto status = read_line(std::cin);
	std::vector<std::string> vec;

	while(!(status.empty())) {
		vec.push_back(status);
		status = read_line(std::cin);

	}

	std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));
	return 0;
}
