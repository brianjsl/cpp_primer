#include "Basket.h"

double Basket::total_receipt(std::ostream& os) const {
	double sum = 0.0;

	//upper_bound goes to the first element larger with key larger than current
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
};
