#include "Limited_bulk_quote.h"

double Limited_bulk_quote::net_price(std::size_t cnt) const {
	if (cnt <= quantity) {
		return cnt * (1 - discount) * price;
	}
	else {
		return quantity * (1 - discount) * price + (cnt - quantity) * price;
	}
};


void Limited_bulk_quote::debug() const {
	this->Quote::debug();
	std::cout << ", quantity: " << quantity << ", discount: " << discount;
};
