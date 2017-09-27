#include "14_30_StrBlobPtrConst.h"
#include "14_30_StrBlobConst.h"
#include <iostream>

int main() {
	ConstStrBlob blob({"Hello", "New", "World"});
	ConstStrBlobPtr plob(blob, 1);
	std::cout << *plob << std::endl;
	std::cout << plob -> size() << std::endl;
	return 0;
}