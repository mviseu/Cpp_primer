#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;
using std::cin;
using std::cout;
using std::endl;


void process(shared_ptr<int> ptr) {
	cout << ptr.use_count() << endl;
	if(ptr.unique()) {
		cout << ++*ptr << endl;
	}
}

int main() {
	//dynamically allocated ints with value of 0
	auto p = new int(42);
	auto sp = make_shared<int>();

	//process(sp);
	//New constructor is explicit:
	//process(shared_ptr<int>(new int()));

	//New constructor is explicit. process will delete dynamic object which means
	//p will become a dangling ptr.:
	//process(shared_ptr<int>(p));
	//p = nullptr;

	cout << "sp use count: " << sp.use_count() 
		 << " sp value: " << *sp << endl;
	cout << "p: " << *p << endl;
	return 0;
}