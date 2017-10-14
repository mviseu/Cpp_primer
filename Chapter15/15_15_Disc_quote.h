#pragma once

#include "15_3_Quote.h"
#include <string>
#include <iostream>

class Disc_quote : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double price, std::size_t qty,
             double dsct)
      : Quote(book, price), quantity(qty), discount(dsct) {}
  double net_price(std::size_t) const override = 0;
  void debug(std::ostream &os) const override;

protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};