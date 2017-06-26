#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::bind;
using namespace std::placeholders;

bool checkSize(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

int main() {
	vector<int> vec = {1, 1, 6, 5, 4, 1};
	auto iter = std::find_if_not(vec.cbegin(), vec.cend(), bind(checkSize, "Hello", _1)); 
	if(iter != vec.cend()) {
		cout << *iter << endl;
	}
	return 0;
}