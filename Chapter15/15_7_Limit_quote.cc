#include "15_7_Limit_quote.h"
#include "15_3_Quote.h"
#include <iostream>

void Limit_quote::debug(std::ostream &os) const {
	Quote::debug(os);
	os << "Threshold quantity " << threshold_qt << " discount " << discount;
}

double Limit_quote::net_price(std::size_t n) const {
  if (n > threshold_qt) {
    return price * (threshold_qt * (1 - discount) + (n - threshold_qt));
  } else {
    return price * n * (1 - discount);
  }
}
