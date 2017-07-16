#include "Employee.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	Employee a;
	Employee b("b");
	cout << a.name << " " << a.identifier << endl;
	cout << b.name << " " << b.identifier << endl;

	return 0;
}