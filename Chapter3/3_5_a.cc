#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){

	string s1, s, sSum;

	//read the first string
	cin >> s1;

	while(cin >> s) {
		sSum += " " + s;
	}
	cout << s1 + sSum << endl;

	return 0;
}
