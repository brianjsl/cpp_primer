#include "Bulk_quote.h"
#include <iostream>
using std::cout;

void main156() {
	Quote q("0-545-01022-5", 3.99);
	Bulk_quote q2("0-545-01022-5", 3.99, 5, 0.2);
	print_total(cout, q, 8);
	print_total(cout, q2, 8);
}
