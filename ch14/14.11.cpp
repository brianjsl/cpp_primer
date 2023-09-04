#include <iostream>
#include "Headers/Sales_data.h"
using namespace std;

/*
This input operator does not check for invalid inputs. 
Thus, if we gave the operator the data in the second 
example, we would get an invalid stream state, and thus 
get an error. 
*/
istream& operator>>(istream& in, Sales_data& s) {
	double price;
	in >> s.bookNo >> s.units_sold >> price;
	s.revenue = s.units_sold * price;
	return in;
}