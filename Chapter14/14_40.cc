#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::string;

struct ShorterString {
public:
	bool operator() (const string &s1, const string &s2) const {
		return s1.size() < s2.size();
	}
};

class SizeComp {

public:
	SizeComp(std::size_t sz) : _sz(sz) {}
	bool operator() (const string &s) const {return s.size() >= _sz;}

private:
	std::size_t _sz;

};

class PrintString {
public:
	PrintString(std::ostream &out, char sp) : os(out), sep(sp) {}
	void operator() (const string &s) {os << s << sep;}
private:
	std::ostream &os;
	char sep;

};


string plural(size_t ctr, const string word) {
	return ctr > 1 ?  word + "s" : word;
}

vector<string> &elimDupl(vector<string> &words) {
	sort(words.begin(), words.end());
	auto unique_end = unique(words.begin(), words.end());
	words.erase(unique_end, words.end());
	return words;
}

void biggies(vector<string> &words, string::size_type sz) {
	elimDupl(words);
	stable_sort(words.begin(), words.end(), ShorterString());
	auto startSize = find_if(words.begin(), words.end(), SizeComp(sz));
	auto ctr = words.cend() - startSize;
	cout << ctr << " " << plural(ctr, "word") << " of length " << sz << " or longer" << endl;
	for_each(startSize, words.end(), PrintString(std::cout, ' '));
	cout << endl;
}

int main() {
	vector<string>words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	biggies(words, 5);
	return 0;
}

