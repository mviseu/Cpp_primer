#include "15_3_Quote.h"
#include <iostream>

void Quote::debug(std::ostream &os) const {
	os << "Book " << bookNo << " sales price " << price;
};

double print_total(std::ostream &os, Quote &item, std::size_t n) {
	auto ret = item.net_price(n);
	os << "Book with isbn "<< item.isbn() << " sold " << n << " items, with a total sales of "
	   << ret;
	return ret;
}

Quote* Quote::clone() const & {
	return new Quote(*this);
}

Quote* Quote::clone() && {
	return new Quote(std::move(*this));

}