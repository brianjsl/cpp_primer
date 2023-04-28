// Exercise 1.20
#include "Sales_data.h"
#include <iostream>

int main() {
  Sales_data data1, data2;
  double price1, price2;
  std::cin >> data1.bookNo >> data1.units_sold >> price1;
  std::cin >> data2.bookNo >> data2.units_sold >> price2;

  data1.revenue = data1.units_sold * price1;
  data2.revenue = data2.units_sold * price2;

  std::cout << data1.bookNo << data1.units_sold
            << data1.revenue / data1.units_sold << std::endl;

  std::cout << data2.bookNo << data2.units_sold
            << data2.revenue / data2.units_sold << std::endl;

  return 0;
}