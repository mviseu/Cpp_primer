#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	//declare 2 empty string objects
	string s1, s2;
	//read the input into the 2 strings
	cin >> s1 >> s2;
	//two strings are equal if they have the same length and the same characters
	if(s1 == s2) {
		cout << "The strings are equal!" << endl;
	} else {
		if(s1 > s2) {
			cout << s1 << " is larger than " << s2;
		} else {
			cout << s2 << " is larger than " << s1;
		}
	}
	
	return 0;
}