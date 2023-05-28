#include "Sales_data.hpp"
#include <set>
using std::multiset;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.isbn() < rhs.isbn();
}

int main() {
  multiset<Sales_data, bool *(const Sales_data &, const Sales_data &)> ma;
  return 0;
}