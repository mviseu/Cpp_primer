#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	//read a string
	string s, sNew;

	cin >> s ;
	for(auto c : s) {
		if(!ispunct(c)) {
			sNew += c;
		}
	}

	cout << sNew << endl;
	return 0;
}