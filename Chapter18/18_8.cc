#include "18_8_Query.h"
#include "18_8_TextQuery.h"
#include "18_8_QueryResult.h"
#include <fstream>
#include <iostream>

int main() {
	std::ifstream file("input_text.txt");

	TextQuery text(file);

	Query qr("Alice");
	Query qr2("her");
	Query qr3("red");


	print(std::cout, qr2.eval(text, 2, 8));
	print(std::cout, (qr & qr3).eval(text, 2, 8));
	print(std::cout, (qr | qr2).eval(text, 2, 8));
	print(std::cout, (~(qr | qr2)).eval(text, 3, 8));
	return 0;
}	