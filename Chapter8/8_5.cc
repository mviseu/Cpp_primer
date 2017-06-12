#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using std::ifstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;


void read(const string &filename, vector<string> &vec) {
	ifstream in(filename);
	string word;
	while(in >> word) {
		vec.push_back(word);
	}
} 

int main() {
	string f = "infile";
	vector<string> vs;
	read(f, vs);
	for(const auto &s : vs) {
		cout << s << endl;
	}
	return 0;
}



