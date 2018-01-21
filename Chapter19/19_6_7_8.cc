#include "19_6_AndQuery.h"
#include "19_6_BaseQuery.h"
#include "19_6_NotQuery.h"
#include <iostream>
#include <typeinfo>


void cast_to_and_query(BaseQuery *ptr_base) {
	if(auto ptr_and = dynamic_cast<AndQuery*>(ptr_base)) {
		std::cout << "Successful cast from BaseQuery to AndQuery Ptr" << std::endl;
	} else {
		std::cout << "Unsuccessful cast from BaseQuery to AndQuery Ptr" << std::endl;
	}
}

void cast_to_and_query(const BaseQuery &ref_base) {
	try {
		auto ref_and = dynamic_cast<const AndQuery &>(ref_base);
		std::cout << "Successful cast from BaseQuery to AndQuery Reference" << std::endl;
	} catch(const std::bad_cast &bc) {
		std::cout << bc.what() << std::endl;
	}
}

bool is_type_and_query(BaseQuery *ptr_base) {
	if(typeid(*ptr_base) == typeid(AndQuery)) {
		return true;
	}
	return false;
}

bool points_to_same_type(BaseQuery *lhs, BaseQuery *rhs) {
	if(typeid(*lhs) == typeid(*rhs)) {
		return true;
	}
	return false;
}


int main() {
	Query alice("Alice");
	Query dad("dad");
	auto alice_and_dad = alice & dad;
	auto alice_or_dad = alice | dad;
	const BaseQuery &alice_and_dad_ref = *alice_and_dad.get();
	const BaseQuery &alice_or_dad_ref = *alice_or_dad.get();

	cast_to_and_query(alice_and_dad.get());
	cast_to_and_query(alice_or_dad.get());

	cast_to_and_query(alice_and_dad_ref);
	cast_to_and_query(alice_or_dad_ref);

	std::cout << "Is alice_and_dad AndQuery?" << std::endl;
	std::cout << is_type_and_query(alice_and_dad.get()) << std::endl;

	std::cout << "Is alice_or_dad AndQuery?" << std::endl;
	std::cout << is_type_and_query(alice_or_dad.get()) << std::endl;

	std::cout << "Do alice_and_dad and alice_or_dad point to the same type?" << std::endl;
	std::cout << points_to_same_type(alice_or_dad.get(), alice_and_dad.get()) << std::endl;



	return 0;
}