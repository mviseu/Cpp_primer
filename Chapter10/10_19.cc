#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::string;

string plural(size_t ctr, const string word) {
	return ctr > 1 ?  word + "s" : word;
}

vector<string> &elimDupl(vector<string> &words) {
	std::sort(words.begin(), words.end());
	auto unique_end = std::unique(words.begin(), words.end());
	words.erase(unique_end, words.end());
	return words;
}

void biggies(vector<string> &words, string::size_type sz) {
	elimDupl(words);
	std::stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2){return s1.size() < s2.size();});
	auto startLessSize = std::stable_partition(words.begin(), words.end(), [sz](const string &s1) {return s1.size() >= sz;});
	auto ctr = startLessSize - words.begin();
	cout << ctr << " " << plural(ctr, "word") << " of length " << sz << " or longer" << endl;
	std::for_each(words.begin(), startLessSize, [](const string &s) {cout << s << " ";});
	cout << endl;
}

int main() {
	vector<string>words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	biggies(words, 5);
	return 0;
}

