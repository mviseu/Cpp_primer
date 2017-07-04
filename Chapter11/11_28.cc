#include <vector>
#include <string>
#include <map>
#include <iostream>

using std::map;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
	map<string, vector<int>> m = {{"Hi", {0, 1}}};
	map<string, vector<int>>::iterator f = m.find("Hi");
	if(f != m.cend()) {
		if(!f->second.empty())
			cout << f->second[0] << endl;
	}
	return 0;
}