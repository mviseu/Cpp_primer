#include "16_28_SharedPtr.h"
#include "16_28_UniquePtr.h"
#include "DebugDelete.h"
#include <iostream>
#include <memory>
#include <string>

using std::unique_ptr;
using std::shared_ptr;

int main() {
	/*{
		SharedPtr<std::string> sptr_string(new std::string("Hello"));
		SharedPtr<int> sptr(new int(4));
		//SharedPtr<std::string> ptr_default;
		SharedPtr<int> sptr_copy_construct(sptr); 
		SharedPtr<long> sptr_move_construct(SharedPtr<long>(new long(3)));
		//SharedPtr<int> sptr_debug(new int(2), DebugDelete());

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

		
		std::shared_ptr<int> sptr_debug(new int(2), DebugDelete());
		{
			std::shared_ptr<int> sptr_debug_copy(std::move(sptr_debug));
			//deleted debug
		}
		

		SharedPtr<int> sptr_debug(new int(2), DebugDelete());
		{
			SharedPtr<int> sptr_debug_copy(std::move(sptr_debug));
			//deleted debug
		}
		std::cout << "End of scope of second ptr" << std::endl;
		

		
		std::shared_ptr<int> sptr_debug(new int(2), DebugDelete());
		{
			std::shared_ptr<int> sptr_assign(new int(3));
			sptr_assign = std::move(sptr_debug);
		}
		std::cout << "End of scope of second ptr" << std::endl;
		

		
		move-assign moves the deleter
		copy-assign does not copy the deleter
		Same with copy/move constructors
		


		SharedPtr<int> sptr_debug(new int(2), DebugDelete());
		{
			SharedPtr<int> sptr_assign(new int(3));
			sptr_assign = sptr_debug;
		}
		std::cout << "End of scope of second ptr" << std::endl;
		
		SharedPtr<int> ptr_default;
		std::cout << ptr_default.unique() << std::endl;
		std::cout << ptr_default.use_count() << std::endl;


		SharedPtr<int> sptr_reset(new int(2));
		sptr_reset.reset(nullptr);
		std::cout << sptr_reset.use_count() << std::endl;


		SharedPtr<int> sptr_test(nullptr);
		std::cout << sptr_test.use_count() << std::endl;
		

		
			When constructing with nullptr, use_count = 0.
			When reset with nullptr, error -> we haven't enforced this behaviour yet
		

		SharedPtr<int> some_ptr(nullptr);
		SharedPtr<int> another_ptr(new int(3));
		another_ptr = some_ptr;
		std::cout << another_ptr.use_count() << std::endl;
	}*/

	//std::cout << "Unique ptr" << std::endl;

	// unique pointer

	/*UniquePtr<std::string, DebugDelete> uptr_string(new std::string("Hello"), DebugDelete());
	UniquePtr<int> uptr(new int(4));
	UniquePtr<int> uptr_default(new int(6));

	UniquePtr<int> uptr_move_construct(UniquePtr<int>(new int(3)));

	uptr_move_construct.swap(uptr_default);
	std::cout << "swap: " << *uptr_move_construct << std::endl;

	std::cout << (*uptr) << std::endl;
	if(uptr_string) {
		std::cout << uptr_string->size() << std::endl;
		std::cout << *uptr_string.get() << std::endl;
	}*/

	/*int *ptr = nullptr;
	{
		unique_ptr<int, DebugDelete> uptr_debug(new int(2), DebugDelete());
		ptr = uptr_debug.release();
		uptr_debug.reset(new int(2));
	}
	std::cout << "End of uptr_debug scope" << std::endl;
	*/

	/*
	{
		UniquePtr<int> sptr_debug(new int(2));
		sptr_debug = std::move(UniquePtr<int>(new int(2)));
	}
	std::cout << "End of sptr_debug scope" << std::endl;
	*/

	/*
	UniquePtr<int, DebugDelete> uptr(new int(2), DebugDelete());
	{
		SharedPtr<int> sptr(std::move(uptr));
		{
			SharedPtr<int> sptr_to_swap(new int(3));
			sptr_to_swap.swap(sptr);
			std::cout << "sptr to swap: " << *sptr_to_swap << std::endl;
		}
		std::cout << "End of sptr to swap scope" << std::endl;
		std::cout << "sptr " << *sptr << std::endl;
	}
	std::cout << "end of shared ptr scope" << std::endl;
	*/
	UniquePtr<int> uptr(new int(3));
	return 0;
}
