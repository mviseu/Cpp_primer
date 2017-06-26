#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::string;

vector<string>::size_type count(vector<string>words, string::size_type sz) {
	return std::count_if(words.cbegin(), words.cend(), [sz](const string &s1) {return s1.size() > sz;});
}
int main() {
	vector<string>words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	cout << count(words, 5) << endl;
	return 0;
}

