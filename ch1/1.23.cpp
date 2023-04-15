#include "Sales_item.h"
#include <iostream>

int main() {
  Sales_item val, currVal;
  if (std::cin >> currVal) {
    int cnt = 1;
    while (std::cin >> val) {
      if (val.isbn() == currVal.isbn()) {
        ++cnt;
      } else {
        std::cout << currVal.isbn() << " has " << cnt << " transactions\n";
        currVal = val;
        cnt = 1;
      }
    }
    std::cout << currVal.isbn() << " has " << cnt << " transactions"
              << std::endl;
  }
  return 0;
}