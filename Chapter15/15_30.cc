#include "Basquet.h"
#include "15_3_Quote.h"
#include "15_27_Bulk_quote.h"
#include <iostream>

int main() {
	Basquet h;
	Quote q1("Quote_book", 2);
	auto q2 = q1;
	Bulk_quote b1("Bulk_quote_book", 2, 1, 0.5);
	auto b2 = b1;
	h.add_item(b1);
	h.add_item(b2);
	h.add_item(q1);
	h.add_item(q2);
	h.total_receipt(std::cout);
	return 0;
}