#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

string addPrefixAndSuffix(const string &name, const string &pre, const string &suff) {
	string s = " " + name + " ";
	s.insert(s.begin(), pre.begin(), pre.end());
	return s.append(suff.begin(), suff.end());
}


int main() {
	string s = addPrefixAndSuffix("Elizabeth", "Queen", "II");
	cout << s << endl;
	return 0;
}