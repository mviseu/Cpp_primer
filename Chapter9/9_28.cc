#include <string>
#include <forward_list>
#include <iostream>

using std::string;
using std::forward_list;
using std::cout;
using std::endl;

forward_list<string>::iterator addElementAfterFind(forward_list <string> &fl, string find, string elem) {
	auto prev = fl.cbefore_begin();
	for(auto iter = fl.cbegin(); iter != fl.cend(); ++prev, ++iter) {	
		if(*iter == find) {
			return fl.insert_after(iter, elem);
		}
	}
	return fl.insert_after(prev, elem);
}



int main() {
	forward_list<string> fl = {"This", "is", "the", "world", "of", "cpp", "primer"};
	addElementAfterFind(fl, "the", "lovely");
	for(const auto &e : fl) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}