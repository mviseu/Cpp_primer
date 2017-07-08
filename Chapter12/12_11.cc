#include <memory>
#include <iostream>

using std::shared_ptr;
using std::cin;
using std::cout;
using std::endl;


void process(shared_ptr<int> ptr, shared_ptr<int> &p) {
	cout << p.use_count() << endl;
	cout << ptr.use_count() << endl;
	if(ptr.unique()) {
		cout << ++*ptr << endl;
	}
}

int main() {
	shared_ptr<int> p(new int(3));
	//Because ptr in process is now initialized with built in pointer it is NOT sharing with p. 
	//now process will delete the allocated object using ptr and p will try to use a deleted object (and delete it again corrupting free store)
	//BUG:
	//process(shared_ptr<int>(p.get()),p);
	cout << p.use_count() << endl;
	return 0;
}