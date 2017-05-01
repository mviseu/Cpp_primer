#include <iostream>
#include <typeinfo>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {

	int i;
	double d;
	const string *ps;
	char *pc;
	void *pv;

	//conversion from pointer to const string to a pointer to void
	//from pointer to const string to pointer to const void -> static_cast
	//removes the const -> const_cast

	pv = (void*)ps;
	const_cast<void*>(static_cast<const void *>(ps));
	cout << typeid(const_cast<void*>(static_cast<const void *>(ps))).name() << endl;

	//static_cast conversion from char to int
	i = int(*pc);
	cout << typeid(static_cast<int>(*pc)).name() << endl;

	//implicit conversion from double * to void *
	pv = &d;
	pv = static_cast<void*>(&d);
	cout << typeid(static_cast<void *>(&d)).name() << endl;

	//conversion from void * to char *
	pc = (char*) pv;
	cout << typeid(static_cast<char *>(pv)).name() << endl;

	return 0;
}