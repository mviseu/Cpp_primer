#include "StrBlobValue.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
		StrBlob str1({"Hello"}), str3(str1);
		StrBlob str2(str1);
		str2.front() = "Goodbye";
		cout << str1.front() << endl;
		cout << str2.front() << endl;
		cout << str3.front() << endl;
		str3 = str2;
		cout << str1.front() << endl;
		cout << str2.front() << endl;
		cout << str3.front() << endl;

	return 0;
}