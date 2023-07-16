#include "Sales_data.hpp"
#include <algorithm>
#include <vector>
using namespace std;

bool compareIsbn(const Sales_data &s1, const Sales_data &s2) {
  return s1.isbn() < s2.isbn();
}

ostream &print(ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
     << item.avg_price();
  return os;
}

void print(const vector<Sales_data> &vec) {
  for (const auto &v : vec) {
    print(cout, v);
    cout << endl;
  }
}
int main() {
  Sales_data s1("803-201X-891I", 10, 4.99);
  Sales_data s2("803-201X-891G", 7, 6.99);
  Sales_data s3("803-201X-891F", 9, 5.99);
  Sales_data s4("803-201X-891I", 3, 8.99);

  vector<Sales_data> vec = {s1, s2, s3, s4};
  stable_sort(vec.begin(), vec.end(), compareIsbn);
  print(vec);
}