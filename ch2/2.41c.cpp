// Exercise 1.22
#include "Sales_data.h"
#include <iostream>

int main() {
  Sales_data data, sum;
  double price = 0.0;

  if (std::cin >> data.bookNo >> data.units_sold >> price) {
    data.revenue = data.units_sold * price;
    sum.bookNo = data.bookNo;
    sum.units_sold = data.units_sold;
    sum.revenue = data.revenue;

    while (std::cin >> data.bookNo >> data.units_sold >> price) {
      if (data.bookNo == sum.bookNo) {
        data.revenue = data.units_sold * price;
        sum.units_sold += data.units_sold;
        sum.revenue += data.revenue;
      } else {
        std::cerr << "Books must have the same ISBN" << std::endl;
      }
    }

    std::cout << sum.bookNo << " " << sum.units_sold << " " << sum.revenue
              << " " << sum.revenue / sum.units_sold << std::endl;
    return 0;
  } else {
    std::cerr << "Must enter a valid book" << std::endl;
    return -1;
  }
}