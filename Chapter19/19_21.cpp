#include "Token.h"

int main() {
	//default constructor, copy constructor, move constructor
	Token tok1, tok2(tok1);
	std::cout << "START";
	auto tok3(std::move(Token()));
	std::cout << "END";
	tok3 = 2;
	tok3 = Sales_data();

	// assignments
	int i{1};
	char c = 'a';
	double d = 2.5;
	std::string s = "Hello";
	Sales_data sd;
	tok1 = i;
	tok1 = d;
	tok1 = c;
	tok1 = s;
	tok1 = sd;

	// copy and move assigments
	tok1 = tok2;
	tok1 = Token();

	return 0;
}