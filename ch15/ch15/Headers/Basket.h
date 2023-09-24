#pragma once
#include "Quote.h"
#include <memory>
#include <set>
#include <iostream>

class Basket
{
public:
	void add_item(const std::shared_ptr<Quote>& sale) { items.insert(sale); }

	void add_item(const Quote& sale) {
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}

	void add_item(Quote&& sale) {
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}

	double total_receipt(std::ostream& os) const;
private:
	static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) {
		return lhs->isbn() < rhs->isbn();
	}

	//mutliset that uses compare function to sort
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

