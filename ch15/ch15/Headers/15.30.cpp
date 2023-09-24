#include "Bulk_quote.h"
#include "Quote.h"
#include "Basket.h"
#include <iostream>

void main1530() {
	Basket b;
	b.add_item(Quote("0-201-54848-8", 19.99));
	b.add_item(Quote("0-201-54848-8", 13.99));
	b.add_item(Quote("0-201-54848-8", 15.99));
	b.add_item(Bulk_quote("0-201-54848-9", 17.99, 5, 0.2));
	b.add_item(Bulk_quote("0-201-54848-9", 17.99, 5, 0.2));
	b.add_item(Bulk_quote("0-201-54848-9", 17.99, 5, 0.2));
	b.add_item(Bulk_quote("0-201-54848-9", 17.99, 5, 0.2));
	b.add_item(Bulk_quote("0-201-54848-9", 17.99, 5, 0.2));
	b.total_receipt(std::cout);
}