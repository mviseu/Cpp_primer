#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <initializer_list>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	StrBlob lines;
	for(string s; getline(cin, s); lines.push_back(s));
	auto ptr = lines.begin();
	for(StrBlob::size_type i = 0; i < lines.size(); ++i, ptr.incr()) {
		cout << ptr.deref() << endl;
	}
	return 0;
}