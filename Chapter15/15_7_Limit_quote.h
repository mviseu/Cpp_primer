#pragma once
#include "15_15_Disc_quote.h"
#include <string>
#include <iostream>

class Limit_quote : public Disc_quote {
public:
  Limit_quote() = default;
  Limit_quote(const std::string &book, double pr, std::size_t thr, double dsct)
      : Disc_quote(book, pr, thr, dsct) {}
  double net_price(std::size_t n) const override;
};
