#include "Sales_data.h"
#include <iostream>

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data res = lhs;
    res.combine(rhs);
    return res;
}

std::istream& operator>>(std::istream& is, Sales_data& item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
        << item.avg_price();
    return os;
}

Sales_data::Sales_data(std::istream& is) { is >> *this; }

Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
   /* this->combine(rhs);
    return *this;*/
    *this = *this + rhs;
    return *this;
}

Sales_data& Sales_data::operator=(std::string s) {
    bookNo = s;
    return *this;
}
