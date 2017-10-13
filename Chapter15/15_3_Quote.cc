#include "15_3_Quote.h"
#include <iostream>

void Quote::debug(std::ostream &os) const {
	os << "Book " << bookNo << " sales price " << price;
};
