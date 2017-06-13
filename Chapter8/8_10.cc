#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::vector;
using std::istringstream;
using std::ifstream;
using std::cout;
using std::endl;
using std::cerr;


int main() {
	ifstream inputFile("infile");

	if(inputFile.fail()) {
		cerr << "Infile invalid" << endl;
		return -1;
	}
	vector<string>lines;
	string line;
	while(getline(inputFile, line)) {
		lines.push_back(line);
	}

	vector<string> words;
	for(const auto &l : lines) {
		istringstream inputString(l);
		string word;
		while(inputString >> word) {
			words.push_back(word);
		}

	}

	for(const auto &w : words) {
		cout << w << endl;
	}
	return 0;
}