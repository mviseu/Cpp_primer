#include "TextQuery_13_42.h"
#include "QueryResult_13_42.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;
using std::cin;

int main() {
	ifstream input("infile");
	TextQuery tq(input);
	while(true) {
		cout << "enter word to look for, or q to quit: \n";
		string s;
		if(!(cin >> s) || s == "q") break;
		print(cout, tq.query(s));
	}
	return 0;
}