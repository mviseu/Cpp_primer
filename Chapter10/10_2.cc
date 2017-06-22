#include <algorithm>
#include <string>
#include <list>
#include <list>
#include <iostream>

using std::string;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main() {
	list<string> vecS;
	string s;
	//do the same but now read values into a list of strings
	while(cin >> s) {
		vecS.push_back(s);
	} 
	const string sref = "hi";
	cout << sref << " was counted " << count(vecS.cbegin(), vecS.cend(), sref) << " times" << endl;

	return 0;
}