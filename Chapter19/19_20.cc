#include "19_20_Query.h"
#include "19_20_TextQuery.h"
#include <fstream>
#include <iostream>

int main() {
	std::ifstream file("input_text.txt");

	TextQuery text(file);
	Query qr("Alice");
	Query qr2("her");
	Query qr3("red");
	print(std::cout, qr2.eval(text, 1, 9));
	print(std::cout, (qr & qr3).eval(text, 1, 9));
	print(std::cout, (qr | qr2).eval(text, 1, 9));
	return 0;
}	