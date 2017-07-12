#include "TextQuery.h"
#include "QueryResult.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;
using std::cin;

int main() {
	ifstream input("infile");
	TextQuery tq(input);
	do {
		cout << "enter word to look for, or q to quit: \n";
		string s;
		if(!(cin >> s) || s == "q") break; 
		print(cout, tq.query(s));
	} while(true);

	return 0;
}