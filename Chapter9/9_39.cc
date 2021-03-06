#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	vector<string> vs;
	//allocate space for at least 1024 elements (expecting lots of elements)
	vs.reserve(1024);
	cout << "size: " << vs.size() << " capacity: " << vs.capacity() << endl;
	string word;
	while(cin >> word) {
		//while read is successful put words at the back of the vector
		vs.push_back(word);
	}
	//expand number of elements by 50% -> added/new elements are value initialized to empty string
	vs.resize(vs.size() + vs.size() / 2);
	for(const auto &e : vs) {
		cout << e << endl;
	}
	cout << "size: " << vs.size() << " capacity: " << vs.capacity() << endl;

	return 0;
}