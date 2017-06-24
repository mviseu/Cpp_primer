#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using std::partition;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

bool hasMoreThan5Char(const string &s) {
	return !(s.size() < 5);
}
void print(vector<string>::const_iterator beg, vector<string>::const_iterator end) {
	for(auto iter = beg; iter != end; ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
}

int main() {
	vector<string> words;
	for(string word; cin >> word; words.push_back(word));
	auto beg = words.begin(), end = words.end();
	print(beg, end);
	auto false_begin = partition(beg, end, hasMoreThan5Char);
	print(beg, false_begin);
	return 0;
}