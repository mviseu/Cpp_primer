#include "15_5_Bulk_quote.h"
#include "15_3_Quote.h"
#include <iostream>

void Bulk_quote::debug(std::ostream &os) const {
	Quote::debug(os);
	os << "Minimum quantity " << min_qt << " discount " << discount;
}

double Bulk_quote::net_price(std::size_t cnt) const {
  if (cnt > min_qt) {
    return cnt * price * (1 - discount);
  } else {
    return cnt * price;
  }
}

