#pragma once
#include "15_15_Disc_quote.h"
#include <string>
#include <iostream>

class Bulk_quote : public Disc_quote {

public:
  Bulk_quote() = default;
  using Disc_quote::Disc_quote;
  double net_price(std::size_t) const override;
  Bulk_quote* clone() const & override;
  Bulk_quote* clone() && override ;

};
