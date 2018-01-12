#include <iostream>
#include <iterator>
#include <string>

std::ostream_iterator<std::string> out(std::cout, "\n");
namespace primerLib {
	void compute() {out = "primerLib::compute()";}
	void compute(const void *ptr) {out = "primerLib::compute(const void *)";}
}

//using primerLib::compute;

void compute(int i) {out = "::compute(int)";}
void compute(double d1, double d2 = 3.14) {out="::compute(double, double = 3.14)";}
void compute(char *ptr1, char *ptr2 = 0) {out="::compute(char *, char * = 0)";}


void f() {
//	using primerLib::compute;
	compute(0);
}

int main() {
	using primerLib::compute;
	f();
	return 0;
}

// Using declaration before main() in global scope

// candidates -> all compute names
// viable
/*
primerLib::compute(const void *) -> 
::compute(int i) -> perfect match, no conversion required
::compute(double d1, double d = 3.14) -> arithmetic conversion from int to double
::compute(char *, char *ptr2 = 0) -> conversion from integer constant expression to char *
::compute(const void *ptr) -> conversion from integer constant expression to const void *
*/

// Using declaration inside f() before calling compute

// candidates -> only the ones in primerLib since functions with the same name are hidden

// viable
/*
primerLib::comput(const void *ptr);
*/

// Using declaration outside f() in main before caling f()

// candidates -> only the ones in the global namespace

// viable
/*
perfect match ::compute(int i)
*/
