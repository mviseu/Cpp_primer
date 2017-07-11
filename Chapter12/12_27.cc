#include "TextQuery.h"
#include <fstream>

using std::ifstream;

int main() {
	ifstream input("infile");
	TextQuery tq(input);
	return 0;
}