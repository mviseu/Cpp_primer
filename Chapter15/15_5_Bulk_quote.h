#pragma once
#include "15_3_Quote.h"
#include <string>
#include <iostream>

class Bulk_quote : public Quote {

public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double sales_price, std::size_t qty,
             double dsct)
      : Quote(book, sales_price), min_qt(qty), discount(dsct) {}
  void debug(std::ostream &os) const override;
  double net_price(std::size_t) const override;

private:
  std::size_t min_qt = 0;
  double discount = 0.0;
};
