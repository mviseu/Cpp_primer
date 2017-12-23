#include <regex>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>

int main() {
	std::cout << "Welcome to regex match! Start by providing an 'input.txt' file to see if 'ie except after c' rule is followed for all words." << std::endl;
	std::ifstream file("input.txt");
	std::string pattern = "[[:alpha:]]*[^c]ei[[:alpha:]]*";
	std::regex forbidden(pattern, std::regex::icase);
	std::string sentence;
	std::vector<std::string> exceptions = {"albeit", "neighbour"};
	while(std::getline(file, sentence)) {
		for(std::sregex_iterator it(sentence.cbegin(), sentence.cend(), forbidden), end; it != end; ++it) {
			if(std::find(exceptions.cbegin(), exceptions.cend(), it->str()) != exceptions.cend()) {
				std::cout << it->str() << " is an exception." << std::endl;
				continue;
			}
			auto pos_pre = it->prefix().length();
			pos_pre = pos_pre > 40 ? pos_pre - 40 : 0;
			std::cout << "Prefix: " << it->prefix().str().substr(pos_pre) << std::endl;
			std::cout << "Forbidden word: " << it->str() << std::endl;
			std::cout << "Suffix: " << it->suffix().str().substr(0, 40) << std::endl;
			
		}
	}
	return 0;
}