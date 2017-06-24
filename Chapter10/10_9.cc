#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::ifstream;

ostream &print(vector<string> vec, ostream &os) {
	for(const auto &s : vec) {
		os << s << " ";
	}
	os << endl;
	return os;
}

 void elimDupl(vector<string> &vec) {
 	auto beg = vec.begin();
 	auto end = vec.end();
 	sort(beg, end);
 	auto after_unique = unique(beg, end);
 	vec.erase(after_unique, vec.end());
 }

vector<string> &appendRead(vector<string> &vec, istream &is) {
	string s;
	while(is >> s) {
		vec.push_back(s);
	}
	return vec;
}

int main() {
	ifstream input("infile");
	vector<string>vec;
	vec = appendRead(vec, input);
	print(vec, cout);
	elimDupl(vec);
	print(vec, cout);
	return 0;
}


