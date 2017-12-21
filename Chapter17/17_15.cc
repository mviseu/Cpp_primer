#include <regex>
#include <iostream>
#include <string>




int main() {
	std::string pattern = "[^c]ei";
	//std::string pattern = "[[:alpha:]]*[^c]ei[[:alpha:]]*";
	std::regex forbidden(pattern, std::regex::icase);
	std::cout << "Welcome to regex match! Start by providing a word to see if 'ie except after c' rule is followed. To quit press 'q'." 
			  << std::endl;
	std::string word;
	while(std::cin >>  word && word != "q") {
		std::smatch result;
		if(std::regex_search(word, result, forbidden)) {
			std::cout << word << " does not follow the rule" << std::endl;
		} else {
			std::cout << "Well done! " << word << " follows the rule" << std::endl;
		}
	}
	return 0;
}