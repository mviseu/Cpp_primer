#include "15_3_Quote.h"
#include "15_5_Bulk_quote.h"
#include "15_7_Limit_quote.h"
#include <iostream>

int main() {

  Quote qt("HelloWorld", 2.1);
  qt.debug(std::cout);
  Bulk_quote bqt("HelloWorld", 2.1, 1, 0.5);
  bqt.debug(std::cout);
  Limit_quote lqt("HelloWorld", 2.1, 1, 0.5);
  lqt.debug(std::cout);
	return 0;
}
