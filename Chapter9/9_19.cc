#include <list>
#include <string>
#include <iostream>

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;


int main() {
	list<string> slist;
	string word;
	while(cin >> word) {
		slist.push_back(word);
	}

	for(auto iter = slist.cbegin(); iter != slist.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}