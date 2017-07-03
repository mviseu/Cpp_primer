#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;
using std::endl;

int main() {
	map<string, int> count_words;
	string s = "Foo";
	int i = count_words[s];
	cout << i << endl;
	return 0;
}