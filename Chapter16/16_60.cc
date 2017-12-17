#include "16_60_SharedPtr.h"
#include "DebugDelete.h"
#include <iostream>
#include <memory>
#include <string>

using std::shared_ptr;

int main() {
	SharedPtr<std::string> sptr_string(new std::string("Hello"));
	SharedPtr<int> sptr(new int(4));
	SharedPtr<std::string> ptr_default;
	SharedPtr<int> sptr_copy_construct(sptr); 
	SharedPtr<long> sptr_move_construct(SharedPtr<long>(new long(3)));
	SharedPtr<int> sptr_debug(new int(2), DebugDelete());

	std::cout << (*sptr) << std::endl;
	if(sptr_string) {
		std::cout << sptr_string->size() << std::endl;
		std::cout << *sptr_string.get() << std::endl;
		std::cout << sptr_string.use_count() << std::endl;
	}
	std::cout << sptr_copy_construct.use_count() << std::endl;
	std::cout << sptr_copy_construct.unique() << std::endl;

	sptr_debug.swap(sptr);
	std::cout << *sptr_debug << std::endl;

	auto sptr_int = MakeShared<int>(3);
	auto sptr_str = MakeShared<std::string>(5, 'c');
	std::cout << *sptr_str << std::endl;

	return 0;
}


