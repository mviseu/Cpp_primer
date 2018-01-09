#include "18_8_Query.h"
#include "18_8_TextQuery.h"
#include "18_8_QueryResult.h"
#include <fstream>
#include <iostream>

int main() {
	std::ifstream file("input_text.txt");

	chapter18::TextQuery text(file);

	chapter18::Query qr("Alice");
	chapter18::Query qr2("her");
	chapter18::Query qr3("red");


	chapter18::print(std::cout, qr2.eval(text, 2, 8));
	chapter18::print(std::cout, (qr & qr3).eval(text, 2, 8));
	chapter18::print(std::cout, (qr | qr2).eval(text, 2, 8));
	chapter18::print(std::cout, (~(qr | qr2)).eval(text, 3, 8));
	return 0;
}	