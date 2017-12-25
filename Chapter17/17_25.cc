#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

int main() {
	std::string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::string format_out = "$2.$5.$7";
	try {
		std::regex phone(pattern);
		std::string line;
		std::ifstream file("infile_phone");
		while(std::getline(file, line)) {
			std::smatch first_phone;
			std::regex_search(line, first_phone, phone);
			std::cout << first_phone.prefix().str() << " " << first_phone.format(format_out) << std::endl;
		}
	} catch(const std::regex_error &exc) {
		std::cout << exc.what() << std::endl;
	}
	return 0;
}