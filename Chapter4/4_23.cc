#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main() {
	string s = "Word";

	// + has higher precedence than equality operator
	// cout has higher precedence than asssign
	cout << (s = s + (s[s.size() - 1] == 's' ? "" : "s"))  << endl;



	return 0;
}
