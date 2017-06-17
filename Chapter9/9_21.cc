#include <list>
#include <vector>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::string;


int main() {
	string word;
	list<string> lst;
	auto iter = lst.cbegin();
	while(cin >> word) {
		iter = lst.insert(iter, word);
	}

	//for vector it is very expensive to read into front. Better to push_back and then sort OR
	//insert into list and then copy to vector
	vector<string> vst(lst.cbegin(), lst.cend());

	for(const auto &e : vst) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}