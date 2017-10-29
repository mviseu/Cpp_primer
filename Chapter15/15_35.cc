#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"

#include <fstream>
#include <iostream>

int main() {
	std::ifstream file("input_text.txt");

	TextQuery text(file);
	Query qr("Alice");
	print(std::cout, qr.eval(text));
	std::cout << qr.rep() << std::endl;
	(~qr).eval(text);
	print(std::cout, (~qr).eval(text));
	return 0;
}	