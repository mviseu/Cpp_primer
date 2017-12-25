#include <regex>
#include <string>
#include <iostream>
#include <fstream>

int main() {
	std::string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::string format = "$2.$5.$7";
	try {
		std::regex phone(pattern);
		std::string line;
		std::ifstream file("infile_phone");
		while(std::getline(file, line)) {
			std::cout << std::regex_replace(line, phone, format) << std::endl;
		}
	} catch(const std::regex_error &exc) {
		std::cout << exc.what() << std::endl;
	}
	return 0;
}