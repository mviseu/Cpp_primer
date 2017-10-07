#include "14_30_StrBlobPtr.h"

class PtrStrBlobPtr {
public:
	PtrStrBlobPtr(StrBlobPtr * pr) : ptr(pr) {}
	StrBlobPtr &operator->() const {return *ptr;} 

private:
	StrBlobPtr * ptr;

};