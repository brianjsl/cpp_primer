#include "Sales_item.h"
#include <iostream>

int main() {
  Sales_item item1;

  while (std::cin >> item1) {
    std::cout << item1 << std::endl;
  }
}