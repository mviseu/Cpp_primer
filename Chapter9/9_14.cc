#include <list>
#include <vector>
#include <string>
#include <iostream>


using std::list;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
	list<const char *>listOldStyleCstring = {"Cpp", "Primer", "Exercises", "After", "Work"};
	vector<string> vecString; //empty
	vecString.assign(listOldStyleCstring.cbegin(), listOldStyleCstring.cend());
	for(const auto &e : vecString) {
		cout << e << " " ;
	}
	cout << endl;
	return 0;
}