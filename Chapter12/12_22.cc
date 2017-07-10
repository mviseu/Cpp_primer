#include "ConstStrBlobPtr.h"
#include "StrBlob_const.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	const StrBlob const_obj({"This", "is", "a", "const", "object"});
	auto ptr = const_obj.begin();
	for(StrBlob::size_type i = 0; i < const_obj.size(); ++i, ptr.incr()) {
		cout << ptr.deref() << endl;
	}
	return 0;
}