#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool stringContainsCapitalLetter(const string &s) {
	bool containsCapitalLetter = false;

	for(const auto &c : s) {
		if(isupper(c)) {
			containsCapitalLetter = true;
			break;
		}
	}

	return containsCapitalLetter;
}

string stringLowerCase(string &s) {


	for(auto &c : s) {
		c = toupper(c);
	}

	return s;
}

int main() {
	cout << stringContainsCapitalLetter("hEllO") << endl;
	
	string sMain = "Hello";
	stringLowerCase(sMain);
	cout << sMain << endl;
	return 0;
}