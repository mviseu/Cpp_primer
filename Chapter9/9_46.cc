#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

string addPrefixAndSuffix(const string &name, const string &pre, const string &suff) {
	//using position, length and insert function
	string s = " " + name + " ";
	return s.insert(0, pre).insert(s.size(), suff);
}


int main() {
	string s = addPrefixAndSuffix("Elizabeth", "Queen", "II");
	cout << s << endl;
	return 0;
}