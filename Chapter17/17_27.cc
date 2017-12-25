#include <regex>
#include <iostream>
#include <fstream>
#include <iterator>

bool validateZip(const std::smatch &m) {
	if(m[2].matched) {
		return m[3].matched;
	}
	return true;
}

std::string readFile(const std::string &filename = "input_zip") {
	// read a file into a string
	std::ifstream file(filename);
	std::istreambuf_iterator<char> file_it(file), file_eof;
	return std::string(file_it, file_eof);
}

int main() {
	std::string pattern = "(\\d{5})(-)?(\\d{4})?";
	std::string format_str = "$1-$3";
	std::ostream_iterator<std::string> out(std::cout, "\n");
	auto file_string = readFile();

	// search for zip patterns
	std::regex zip(pattern);
	for(std::sregex_iterator it(file_string.cbegin(), file_string.cend(), zip), it_end; it != it_end; ++it) {
		// validate zip pattern
		if(validateZip(*it)) {
			out = "Found the zip code: ";
			if(it->str().size() > 5) {
				out = it->format(format_str);
			} else {
				out = it->str();
			}
		}
	}

	return 0;
}