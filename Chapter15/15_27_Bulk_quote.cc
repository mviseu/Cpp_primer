#include "15_27_Bulk_quote.h"
#include "15_15_Disc_quote.h"
#include "15_3_Quote.h"

#include <iostream>

double Bulk_quote::net_price(std::size_t cnt) const {
  if (cnt > quantity) {
    return cnt * price * (1 - discount);
  } else {
    return cnt * price;
  }
}