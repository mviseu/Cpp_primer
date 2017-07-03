#include <map>
#include <vector>
#include <string>
#include <iostream>

using std::map;
using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;

int main() {
	map<string, vector<int>> m;
	pair<string, vector<int>> p = {"hi", {0, 1}};
	pair< map<string, vector<int>>::iterator, bool > r = m.insert(p);

	if(r.second) {
		cout << "was inserted!" << endl;
	}
	return 0;
}