#include "15_7_Limit_quote.h"
#include "15_15_Disc_quote.h"
#include "15_3_Quote.h"

#include <iostream>

double Limit_quote::net_price(std::size_t n) const {
  if (n > quantity) {
    return price * (quantity * (1 - discount) + (n - quantity));
  } else {
    return price * n * (1 - discount);
  }
}
