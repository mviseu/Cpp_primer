#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <fstream>
#include <iostream>

int main() {
	std::ifstream file("input_text.txt");

	TextQuery text(file);
	Query qr("Alice");
	Query qr2("her");
	Query qr3("red");
	print(std::cout, qr2.eval(text));
	print(std::cout, (qr & qr3).eval(text));
	print(std::cout, (qr | qr2).eval(text));
	return 0;
}	