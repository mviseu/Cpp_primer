#include "15_3_Quote.h"
#include "15_5_Bulk_quote.h"
#include "15_7_Limit_quote.h"
#include <iostream>
#include <string>

double print_total(std::ostream &os, const Quote &qt, std::size_t n) {
  auto ret = qt.net_price(n);
  os << "Book with isbn: " << qt.isbn() << " with " << n
     << " copies costs: " << ret << std::endl;
  return ret;
}

int main() {
  Quote qt("HelloWorld", 2.1);
  print_total(std::cout, qt, 2);
  Bulk_quote bqt("HelloWorld", 2.1, 1, 0.5);
  print_total(std::cout, bqt, 2);
  Limit_quote lqt("HelloWorld", 2.1, 1, 0.5);
  print_total(std::cout, lqt, 2);
  return 0;
}
