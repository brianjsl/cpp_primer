#include "Sales_data.hpp"
#include <iostream>
using namespace std;

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data res = lhs;
  res.combine(rhs);
  return res;
}