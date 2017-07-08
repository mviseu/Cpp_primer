#include "12_15.h"
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

connection connect(destination *des) {
	connection con;
	con.ptr = des;
	return con;
}

void disconnect(connection con) {
	cout << "Ending connection with destination: "
		 << con.ptr -> s << endl;
}

int main() {
	destination d;
	d.s = "London";
	auto c = connect(&d);
	shared_ptr<connection>sp(&c, [](connection *p) {disconnect(*p);});
	cout << c.ptr ->s << endl;
	return 0;
}