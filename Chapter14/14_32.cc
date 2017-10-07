#include "14_32_PtrStrBlobPtr.h"
#include "14_16_StrBlob.h"
#include <iostream>

int main() {
	StrBlob a_vec = {"Hello", "this", "is", "a", "test"};
	StrBlobPtr a_vec_index(a_vec, 0);
	PtrStrBlobPtr ptr(&a_vec_index);
	//size of hello
	std::cout << ptr -> size() << std::endl;
	return 0;
}