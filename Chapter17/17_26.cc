#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
	std::string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::string format_str = "$2.$5.$7";
	try {
		std::regex phone(pattern);
		std::string line;
		std::ifstream file("infile_phone");
		while(std::getline(file, line)) {
			std::string name;
			std::string output_str;
			std::size_t count = 0;
			for(std::sregex_iterator it(line.begin(), line.end(), phone), it_end;
				it != it_end; ++it, ++count) {
				if(count == 0) {
					name = it->prefix();
				}
				if(count == 0 || count == 1) {
					output_str = name + it->format(format_str);
				} else {
					output_str += " " + it->format(format_str);
				}
			}
			std::cout << output_str << std::endl;
		}
	} catch(const std::regex_error &exc) {
		std::cout << exc.what() << std::endl;
	}
	return 0;
}