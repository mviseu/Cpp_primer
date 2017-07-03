#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;
using std::endl;

int main() {
	map<string, size_t> m = {{"word", 1}, {"hello", 3}};
	for(map<string, size_t>::const_iterator iter = m.cbegin(); iter != m.cend(); ++iter) {
		cout << iter -> first << " " << iter -> second << endl;
	}
	return 0;
}