#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"

void main1526() {
	Quote q("802-01-X817", 29.32); 
	Bulk_quote b("802-01-X817", 48.99, 3, 0.1);
	q = b;
	Bulk_quote b2("803-07-8401", 24.99, 5, 0.2);
	b = b2;
}