#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

class ReadLine {
public:
	std::string operator() (std::istream &is) {
		std::string s;
		return (getline(is, s) ? s : std::string());
	}
};


int main() {
/*	std::ifstream input("testfile");
	ReadLine read_line;
	std::vector<std::string>vec;
	std::cout << read_line(std::cin) << std::endl;
	for(auto status = read_line(input); !(status.empty()); vec.push_back(status));
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));/*/
	return 0;
}
