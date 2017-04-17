#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
	const string s = "Keep out";

	//c is reference to const char since low-level consts are kept when using auto
	for(auto &c : s) {
		cout << c << endl;

	}

	return 0;
}
