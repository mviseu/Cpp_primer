#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool containsAscenders(string &s) {
	const string ascenders = "bdhklt";
	if(s.find_first_of(ascenders) != string::npos) {
		return true;
	}
	return false;
}

bool containsDescenders(string &s) {
	const string descenders = "fgjpqy";
	if(s.find_first_of(descenders) != string::npos) {
		return true;
	}
	return false;
}

string &updateNotContainsAscOrDesc(string &word, string &longest) {
	const string others = "aceimnorsuvwxz";
	if(word.find_first_not_of(others) == string::npos) {
		return (longest.size() < word.size() ? word : longest);
	}
	return longest;
}

int main() {
	string longest;
	for(string word; cin >> word; longest = updateNotContainsAscOrDesc(word, longest));

	cout << "Longest word that contains neither ascenders nor descenders is: "
		 << longest << endl;
	return 0;
}