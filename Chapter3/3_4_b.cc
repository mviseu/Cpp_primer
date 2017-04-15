#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	string s1, s2;
	
	//read input into two strings
	cin >> s1 >> s2 ;

	if(s1.size() == s2.size()) {
		cout << "The two strings have the same size" << endl;
	} else {
		if(s1.size() > s2.size()) {
			cout << s1 << " is longer than " << s2 << endl;
		} else {
			cout << s2 << " is longer than " << s1 << endl;
		}
	}
	return 0;
}