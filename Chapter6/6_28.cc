#include <iostream>
#include <initializer_list>
#include <string>
#include <typeinfo>

using std::cout;
using std::endl;
using std::initializer_list;
using std::string;

void error_msg(initializer_list<string> i1) {

	//elem is of type const std::string &
	for(const auto &elem : i1) { 
		cout << elem << " "; 
	}
	cout << endl;

}

int main() {
	error_msg({"Testing", "these", "strings"});
	return 0;
}