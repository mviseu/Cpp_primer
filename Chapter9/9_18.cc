#include <deque>
#include <string>
#include <iostream>

using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;


int main() {
	deque<string> sdeque;
	string word;
	while(cin >> word) {
		sdeque.push_back(word);
	}

	for(auto iter = sdeque.cbegin(); iter != sdeque.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}