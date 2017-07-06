#include "StrBlob.h"
#include <initializer_list>
#include <iostream>

using std::cout;
using std::endl;
using std::initializer_list;

int main() {
	StrBlob b1;
	{
		StrBlob b2 ({"a", "an", "the"});
		b1 = b2;
		b2.push_back("about");
	}
	cout << b1.front() << " " << b1.back() << endl;
	b1.pop_back();
	cout << b1.back() << endl;
	cout << b1.empty() << endl;
	cout << b1.size() << endl;
	b1.pop_back();
	b1.pop_back();
	b1.back() = "bye";
	cout << b1.front() << endl;
	cout << b1.back() << endl;
	return 0;
}