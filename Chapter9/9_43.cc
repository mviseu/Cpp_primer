#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
	string s = "John goes thru the woods";
	string old_val = "thru";
	string new_val = "through";

	//erase and insert -> use iterators!
	for(auto iter = s.begin(); iter != s.end() - old_val.size(); ) {
		//if pos + n exceeds size of s, returned value will only copy up to size(end)
		if(s.substr(iter - s.begin(), old_val.size()) == old_val) {
			iter = s.erase(iter, iter + old_val.size());
			iter = s.insert(iter, new_val.begin(), new_val.end());
			iter += new_val.size();
		}
		++iter;
	}
	cout << s << endl;
	return 0;
}