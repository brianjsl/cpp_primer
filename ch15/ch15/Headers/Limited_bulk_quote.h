#pragma once
#include "Disc_quote.h"

class Limited_bulk_quote: public Disc_quote
{
public:
	Limited_bulk_quote() = default;
	Limited_bulk_quote(std::string book, double p, std::size_t q, double disc) : Disc_quote(book, p, q, disc) {};

	double net_price(std::size_t) const override;
	void debug() const override;
};

