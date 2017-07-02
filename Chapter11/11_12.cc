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
	for(pair<string, int>p; cin >> p.first, cin >> p.second; ) {
		vec.push_back(p);
	}
	print(vec);
	return 0;
}
