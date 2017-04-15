#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

	string line, word;

	//reads the standard input a line at a time
	/*while (getline(cin, line)) {
		cout << line << endl;

	} */

	//reads a word at a time
	while(cin >> word)
		cout << word << endl;
	return 0;
}