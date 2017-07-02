#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::pair;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;

void print(const vector<pair<string,int>> & vec) {
	std::for_each(vec.cbegin(), vec.cend(), [](const pair<string, int> &p) {
		cout << p.first << " " << p.second << endl;
	});
}

int main() {
	vector<pair<string, int>> vec;
	string s;
	int i;
	while(cin >> s && cin >> i) {
		//vec.push_back(make_pair(s,i));
		//vec.push_back(pair<string, int> p(s,i));
		vec.push_back({s, i});
	}
	print(vec);
	return 0;
}
