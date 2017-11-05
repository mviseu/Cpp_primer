#include "QueryPtr.h"

int main() {
	std::ifstream file("input_text.txt");

	TextQuery text(file);

	QueryPtr q = ~(QueryPtr("fiery") & QueryPtr("bird") | QueryPtr("wind"));
	//print(std::cout, q.eval(text));
	//q.eval(text);
	std::cout << q;
	print(std::cout, q.eval(text));
	return 0;
}