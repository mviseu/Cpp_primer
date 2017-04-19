//print size and contents of a vector using iterators
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {

	vector<string> v7{10, "hi"} ;
	//Empty vector
	auto v = v7;
	
	for(auto it = v.cbegin(); it != v.cend() ; ++it) {
		cout << *it << endl;

	}

	cout << "The size of v is: " 
		 << v.cend() - v.cbegin() << endl;

	return 0;
}
