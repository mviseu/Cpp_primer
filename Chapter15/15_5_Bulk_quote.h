#pragma once
#include "15_15_Disc_quote.h"
#include <string>
#include <iostream>

class Bulk_quote : public Disc_quote {

public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double sales_price, std::size_t qty,
             double dsct)
      : Disc_quote(book, sales_price, qty, dsct) {}
  double net_price(std::size_t) const override;
};
