#include <iostream>
#include <string>

using std::istream;
using std::cin;
using std::cout;
using std::string;
using std::endl;

istream &readUntilEof(istream &is) {
	string s;
	while(!is.fail()) {
		getline(is, s);
		cout << s << endl;
	}
	is.clear();
	return is;
}

int main() {
	readUntilEof(cin);
	return 0;
}