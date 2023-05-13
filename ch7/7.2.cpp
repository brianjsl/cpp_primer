#include <stdexcept>>
#include <string>
using namespace std;

struct Sales_data {
  string isbn() { return bookNo; };

  Sales_data &combine(Sales_data &rhs);

  std::string bookNo = "";
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data &Sales_data::combine(Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}