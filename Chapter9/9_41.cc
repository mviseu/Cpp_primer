#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::endl;
using std::cout;

int main() {
	vector<char> vc= {'H', 'e', 'l', 'l', 'o'};
	string s(vc.cbegin(), vc.cend());
	for(const auto &c : s) {
		cout << c ;
	}
	cout << endl;
	return 0;
}