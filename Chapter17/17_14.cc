#include <regex>
#include <iostream>

void regexError(const std::string &pattern) {
	try {
		std::regex r(pattern);
	} catch (const std::regex_error &e) {
		//error_
		std::cout << e.what() << " " << e.code() << std::endl;
	}	
}

int main() {
	//error_brack
	regexError("[[:alpha:]");
	//error_paren
	regexError("[^c]ei)");
	//error_ctype
	regexError("[[:invented:]]");
	//error_badrepeat
	regexError("*");
	//error_range
	regexError("[z-a]");
	//error_badbrace
	regexError("a{6, 3}");
	//error_brace
	regexError("a2}");
	return 0;
}