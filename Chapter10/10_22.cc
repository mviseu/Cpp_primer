#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::bind;
using namespace std::placeholders;

bool hasSizeLessOrEqualTo(const string &s, string::size_type size) {
	return s.size() <= size;
}

int main() {
	vector<string> v = {"We", "will", "be", "counting", "the", "words", "with", "six", "characters", "or", "less"};
	cout << std::count_if(v.cbegin(), v.cend(), bind(hasSizeLessOrEqualTo, _1, 6)) << endl;
}