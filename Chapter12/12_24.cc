#include <iostream>
#include <string>

using std::cin;
using std::string;
using std::cout;
using std::endl;

int main() {
	cout << "size?" << endl;
	size_t sz;
	cin >> sz;
	char * p = new char[sz + 1]();
	cout << "string?" << endl;
	cin >> p;
	p[sz] = '\0';
	cout << p << endl;
	delete []p;
	return 0;
}