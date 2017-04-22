#include <iostream>
#include <string>
#include <cstring>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::strcmp;

int main() {
	//declare empty strings
	string s1, s2;

	cout << "Provide the first string" << endl;
	cin >> s1;
	cout << "Provide the second string" << endl;
	cin >> s2;

	if(s1 == s2) {
		cout << "The strings are identical" << endl;
	} else {
		if(s1 < s2) {
			cout << "The first string is smaller than the second string" << endl;
		} else {
			cout << "The first string is larger than the second string" << endl;
		}
	} 


	const char crappyHardcodedString1[] = {'E', 'x', 'p', 'r', 'e', 's','s', 'o', '\0'};
	const char crappyHardcodedString2[] = {'M',  'o', 'c', 'c', 'h', 'a', '\0'};

	if(strcmp(crappyHardcodedString1, crappyHardcodedString2) == 0) {
		cout << "The strings are identical" << endl;
	} else {
		if(strcmp(crappyHardcodedString1, crappyHardcodedString2) < 0) {
			cout << "The first string Expresso is smaller than the second string Moccha" << endl;

		} else {
			cout << "The first string Expresso is larger than the second string Moccha" << endl;
		}
	}

	return 0;
}