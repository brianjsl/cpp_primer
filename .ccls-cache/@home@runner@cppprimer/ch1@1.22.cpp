#include "Sales_item.h"
#include <iostream>

int main() {
  Sales_item total, item;
  if (std::cin >> item) {
    total = item;
    while (std::cin >> item) {
      total += item;
    }
    std::cout << total << std::endl;
  }
}