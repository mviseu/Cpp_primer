#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>

using std::string;
using std::vector;
using std::list;
using std::unique_copy;
using std::back_inserter;
using std::cout;
using std::endl;
using std::for_each;

int main() {
	vector<string> vs = {"what", "what", "are", "the", "elements", "elements", "that", "are", "unique"};
	list<string>ls;
	unique_copy(vs.cbegin(), vs.cend(), back_inserter(ls));
	for_each(vs.cbegin(), vs.cend(), [](const string &s) {cout << s << " ";});
	cout << endl;
	for_each(ls.cbegin(), ls.cend(), [](const string &s) {cout << s << " ";});
	cout << endl;
	return 0;
}