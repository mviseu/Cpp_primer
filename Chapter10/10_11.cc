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

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

ostream &print(vector<string> vec, ostream &os) {
	for(const auto &s : vec) {
		os << s << " ";
	}
	os << endl;
	return os;
}

 void elimDupl(vector<string> &vec, decltype(isShorter) pred) {
 	auto beg = vec.begin();
 	auto end = vec.end();
 	sort(beg, end);
 	auto after_unique = unique(beg, end);
 	end = vec.erase(after_unique, vec.end());
 	stable_sort(beg, end, pred);
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
	elimDupl(vec, isShorter);
	print(vec, cout);
	return 0;
}


