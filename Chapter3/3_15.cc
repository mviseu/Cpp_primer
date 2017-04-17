#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	//default initialize an empty string
	string s1;
	//default initialize an empty vector
	vector<string> v1;

	while(cin >> s1) {
		v1.push_back(s1);
	}

	for(auto &c : v1) {
		cout << c << endl;
	}
	return 0;
}