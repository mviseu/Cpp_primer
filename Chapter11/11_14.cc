#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>

using std::map;
using std::string;
using std::vector;
using std::pair;
using std::back_inserter;
using std::cout;
using std::endl;


map<string, vector<pair<string, string>>> &addFamily(map<string, vector<pair<string, string>>> &families, 
														   const pair<string, vector<pair<string, string>>> &family) {
	families[family.first] = family.second; 
	return families;
}

map<string, vector<pair<string, string>>> &addChildren(map<string, vector<pair<string, string>>> &families, 
														    const string &surname, const vector<pair<string, string>> &children) {
	std::copy(children.cbegin(), children.cend(), std::back_inserter(families[surname])); 
	return families;
}

void print(const pair<string, string> & p) {
	cout << p.first << " " << p.second << " ";
}


void printFamilies(const map<string, vector<pair<string, string>>>&families) {
	for(const auto &family : families) {
		cout << family.first << " ";
		for(const auto &child : family.second) {
			print(child);
		}
		cout << endl;
	}

}

int main() {
	//empty map
	map<string, vector<pair<string, string>>>families;
	//add a family
	const vector<pair<string, string>> children = {{"Ella", "2/10/2000"}, {"Beth", "3/10/1998"}, {"John", "3/10/1998"}};

	addFamily(families, std::make_pair(string("Smith"), children));


	const vector<pair<string, string>> new_children = {{"Mary", "2/10/1990"}, {"william", "2/10/1990"}};

	addChildren(families, string("Smith"), new_children);

	printFamilies(families);
	return 0;
}