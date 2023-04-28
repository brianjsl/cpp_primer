#include "Sales_data.h"
#include <iostream>
#include <string>

int main() {
  Sales_data data1, data2;
  double price = 0;

  // Read in data1
  std::cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;

  // Read in data2
  std::cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;

  // Check equal isbn, then add sum
  if (data1.bookNo == data2.bookNo) {
    unsigned totalCnt = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;

    std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";

    if (totalCnt != 0) {
      std::cout << totalRevenue / totalCnt << std::endl;
    } else {
      std::cout << "(no sales)" << std::endl;
    }
    return 0;
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
    return -1;
  }
}