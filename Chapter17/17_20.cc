#include <regex>
#include <string>
#include <iostream>

bool isValid(const std::smatch &m) {
	if(m[1].matched) {
		return m[3].matched && (!m[4].matched || m[4].str() == " ");

	} else {
		return !m[3].matched && m[4].str() == m[6].str();

	}
}

int main() {
	std::string phone_pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::regex phone(phone_pattern);
	std::string line;
	while(std::getline(std::cin, line)) {
		for(std::sregex_iterator it(line.cbegin(), line.cend(), phone), it_end;
			it != it_end; ++it) {
			if(isValid(*it)) {
				std::cout << "The phone number: " << it->str() << " is valid." << std::endl;
			} else {
				std::cout << "The phone number: " << it->str() << " is not valid" << std::endl;
			}
		}
	}
	return 0;
}