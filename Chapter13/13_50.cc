#include "String.h"
#include <vector>

using std::vector; 

int main() {
	vector<String> vec;
	for(auto i = 0; i < 10;++i) {
		vec.push_back("Hello");
	}
	return 0;
}