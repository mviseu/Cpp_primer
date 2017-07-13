#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>

using std::ifstream;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::istringstream;
using std::endl;
using std::ostream;

vector<string> getFile(ifstream &input) {
	vector<string> file;
	for(string line; getline(input, line); file.push_back(line)) {}
	return file;
}
map<string, set<size_t>> buildMap(const vector<string>&file) { 
	map<string, set<size_t>> wm;
	for(size_t i = 0; i != file.size(); ++i) {
		istringstream input_line(file[i]);
		string word;
		while(input_line >> word) {
			wm[word].insert(i);
		}
	}
	return wm;
}

void printMap(const map<string, set<size_t>> &wm) {
	for(const auto &pair : wm) {
		cout << pair.first << " ";

		for(const auto &nr_line : pair.second) {
			cout << nr_line << " ";
		}
		cout << endl;
	}
}

ostream &print(ostream &os, const string &sought, const vector<string>&file, const set<size_t>&lines) {
	os << sought << " occurs " << lines.size() 
	   << (lines.size() != 1 ? " times" : " time") << endl;
	for(const auto &i : lines) {
		os << "(line " << i + 1 << ") " << file[i] << endl;
	}
	return os;
}

int main() {
	ifstream input("infile");
	auto file = getFile(input);
	auto wm = buildMap(file);
	printMap(wm);

	while(true) {
		cout << "enter word to look for, or q to quit: \n";
		string s;
		if(!(cin >> s) || s == "q") break;

		auto ret = wm.find(s);
		if(ret == wm.end()) {
			print(cout, s, file, set<size_t>());
		} else {
			print(cout, s, file, ret -> second);
		}
	}
	return 0;
}