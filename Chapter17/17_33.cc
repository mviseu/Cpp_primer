#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <random>
#include <ctime>

using std::map;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::runtime_error;
using std::istringstream;

int selectTransformation(int max_no_transformations) {
	static std::default_random_engine e(std::time(0));
	std::uniform_int_distribution<int> u{0, max_no_transformations - 1};
	return u(e);
}

std::multimap<string, string> buildMap(ifstream &in) {
	std::multimap<string, string> m;
	string key, value;
	while(in >> key && getline(in, value)) {
		if(!(value.size() > 1)) {
			throw runtime_error("Error! Add rule for key " + key);			
		}

		m.insert(std::make_pair(key, value.substr(1)));
	}
	return m;
}

const string &transform(const string &word, const std::multimap<string, string> &transf_map) {
	auto word_find = transf_map.find(word);
	if(word_find == transf_map.cend()) {
		return word;
	}
	for(auto i = 0; i < selectTransformation(transf_map.count(word)); ++i, ++word_find);
	return word_find -> second;
}

void wordTransform(ifstream &map_file, ifstream &input) {
	auto transf_map = buildMap(map_file);
	string line;
	while(getline(input, line)) {
		istringstream words(line);
		string word;
		while(words >> word) {
			cout << transform(word, transf_map) << " ";
		}
		cout << endl;
	}
}

void print(const map<string, string>& m) {
	for(const auto &elem : m) {
		cout << elem.first << " " << elem.second << endl;
	}
}


int main() {
	ifstream map_file("map_file"), input("input_word_map");
	wordTransform(map_file, input);
	return 0;
}

