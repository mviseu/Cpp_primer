#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
	string s = "John goes thru the woods";
	string old_val = "thru";
	string new_val = "through";

	//erase and insert
	for(size_t i = 0; i != s.size() - old_val.size(); ) {
		//if pos + n exceeds size of s, returned value will only copy up to size(end)
		if(s[i] == old_val[0] && s.substr(i, old_val.size()) == old_val) {
			s.replace(i, old_val.size(), new_val);
			i += new_val.size();
		} else {
			++i;
		}
	}
	cout << s << endl;
	return 0;
}