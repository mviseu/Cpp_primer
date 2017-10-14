#include "15_15_Disc_quote.h"
#include "15_3_Quote.h"
#include <iostream>

void Disc_quote::debug(std::ostream &os) const {
	Quote::debug(os);
	os << "Quantity " << quantity << " Discount " << discount; 
}