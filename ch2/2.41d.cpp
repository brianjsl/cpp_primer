#include "Sales_data.h"
#include <iostream>

int main() {
  Sales_data val, currVal;
  unsigned units_sold;
  double price = 0.0;
  if (std::cin >> currVal.bookNo >> units_sold >> price) {
    int cnt = 1;
    while (std::cin >> val.bookNo >> units_sold >> price) {
      if (val.bookNo == currVal.bookNo) {
        ++cnt;
      } else {
        std::cout << currVal.bookNo << " has " << cnt << " transactions\n";
        currVal.bookNo = val.bookNo;
        cnt = 1;
      }
    }
    std::cout << currVal.bookNo << " has " << cnt << " transactions"
              << std::endl;
  }
  return 0;
}