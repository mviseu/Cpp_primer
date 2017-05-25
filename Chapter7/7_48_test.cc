#include "7_48.h"
#include <string>

using std::string;

int main() {
	//1 allowed implicit conversion from const char * to string
	//1 direct initialization from string to Sales_data -> allowed ( even if constructor is explicit)
	string null_isbn("9-999-99999-9");
	//string direct initialization is always allowed (even with explicit constructor)
	Sales_data item1(null_isbn);
	return 0;
}