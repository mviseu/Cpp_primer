#include "HasPtr.h"

int main() {
	HasPtr p("hello"), p1(p), p2;
	p2 = p1;
	p2 = p2;
	return 0;
}