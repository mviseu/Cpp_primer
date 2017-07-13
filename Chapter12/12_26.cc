#include <memory>
#include <string>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::allocator;
using std::istream_iterator;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::uninitialized_copy;
using std::for_each;

int main() {


	cout << "size?" << endl;
	size_t size{0};
	cin >> size;

	istream_iterator<string> it(cin), eof;
	allocator<string> all;
	auto const b = all.allocate(size);
	auto e = uninitialized_copy(it, eof, b);
	for(auto p = b; p != e; ++p) {
		cout << *p << endl;
		all.destroy(p);
	}
	all.deallocate(b, size);
	

	return 0;
}