#include <iostream>
#include <string>
#include <sstream>

using std::istream;
using std::istringstream;
using std::cout;
using std::cin;
using std::string;
using std::endl;

istream &readUntilEof(istream &is) {
	string s;
	while(is >> s) {
		cout << s << endl;
	}
	is.clear();
	return is;
}

int main() {
	istringstream inputS("Hello World");
	if(inputS.good()) {
		readUntilEof(inputS);
	}
	return 0;
}