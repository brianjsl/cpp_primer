#include "Bulk_quote.h"
#include <iostream>

double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= quantity) {
		return cnt * (1 - discount) * price;
	}
	else
		return cnt * price;
};

void Bulk_quote::debug() const {
	this->Quote::debug();
	std::cout << ", min_qty: " << quantity << ", discount: " << discount;
}
