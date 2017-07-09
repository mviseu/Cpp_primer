#include <memory>
#include <iostream>

using std::unique_ptr;
using std::cout;
using std::endl;

int main() {
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	cout << ix << " " << *pi << " " << *pi2 << endl;
	//typedef unique_ptr<int> IntP;
	//not allowed: initializing unique_ptr with int
	//IntP po(ix);

	//problem: will try to free ix when out of scope but ix is not dynamically allocated (not allocated using new)
	//IntP p1(pi);

	//legal: do not de-reference *pi2 after p2 goes out of scope
	//not a great idea to mix smart/built in pointers
	//dangling pi2
	//IntP p2(pi2);

	//similar problem to 2). Trying to free ix when it is not allocated with new.
	//IntP p3(&ix);

	//legal, safe
	//IntP p4(new int(2048));

	// problem at tun time since p2 and p5 delete int twice (corruption of free store)
	//IntP p5(p2.get());

	return 0;
}