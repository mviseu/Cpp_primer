#include <cstring>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
	char p1[] = "Cpp", p2[] = "Primer";
	auto sz = strlen(p1) + strlen(p2) + 1;
	char * ptr = new char[sz];
	strcpy(ptr, p1);
	strcat(ptr, " ");
	strcat(ptr, p2);
	cout << ptr << endl;
	delete [] ptr;

	string *sptr = new string();
	string cpp = "Cpp", primer  = " primer", s = cpp + primer;
	cout << (*sptr = s);
	delete sptr;


	return 0;
}