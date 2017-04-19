#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	vector<string> text {"Let me see...", 
	"if we have a paragrapgh next.","","Oh yes we do!"};

	for(auto it = text.begin(); it != text.end() && 
								!it->empty(); ++it) {
		for(auto &c : *it) {
			c = toupper(c) ;
		}	

	}

	//const auto &c does NOT create a copy of c and is more efficient
	for(const auto &c : text) {
		cout << c << endl;
	}

	return 0;
}