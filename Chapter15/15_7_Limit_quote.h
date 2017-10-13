#include "15_3_Quote.h"
#include <string>
#include <iostream>

class Limit_quote : public Quote {
public:
  Limit_quote() = default;
  Limit_quote(const std::string &book, double pr, std::size_t thr, double dsct)
      : Quote(book, pr), threshold_qt(thr), discount(dsct) {}
  void debug(std::ostream &os) const override;
  double net_price(std::size_t n) const override;

private:
  std::size_t threshold_qt = 0;
  double discount = 0.0;
};
