#include "TextQuery.h"
#include "QueryResult.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;

int main() {
	ifstream in("infile");
	TextQuery tq(in);
	TextQuery tq1(tq);
	print(cout, tq.query("this"));
	print(cout, tq1.query("a"));
	tq1 = tq;
	print(cout, tq1.query("a"));
	QueryResult a = tq1.query("hi");
	print(cout, a);
	a = tq1.query("is");
	print(cout, a);

	return 0;
}