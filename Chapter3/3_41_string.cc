#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
	char ca[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
	string caString = ca;
	const char *p = caString.c_str();

	cout << caString << endl;


	return 0;
}
