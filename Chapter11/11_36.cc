#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>

using std::map;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::runtime_error;
using std::istringstream;

const map<string, string> buildMap(ifstream &in) {
	map<string, string> m;
	string key, value;
	while(in >> key && getline(in, value)) {
		if(value.size() > 1) {
			m[key] = value.substr(1);
		} else {
			throw runtime_error("Error! Add rule for key " + key);
		}
	}
	return m;
}

const string &transform(const string &word, const map<string, string> &transf_map) {
	auto word_find = transf_map.find(word);
	return (word_find != transf_map.cend() ? word_find -> second : word);
	}

void wordTransform(ifstream &map_file, ifstream &input) {
	map<string, string> transf_map;
	try {
		transf_map = buildMap(map_file);
		string line;
		while(getline(input, line)) {
			istringstream words(line);
			string word;
			while(words >> word) {
				cout << transform(word, transf_map) << " ";
			}
			cout << endl;
		}
	} catch(runtime_error err) {
		cout << err.what() << endl;
	}
}

void print(const map<string, string>& m) {
	for(const auto &elem : m) {
		cout << elem.first << " " << elem.second << endl;
	}
}


int main() {
	ifstream map_file("map_file"), input("input");
	wordTransform(map_file, input);
	return 0;
}

