// Exercise 1.21
#include "Sales_data.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  Sales_data data1, data2;
  double price1, price2;
  cin >> data1.bookNo >> data1.units_sold >> price1;
  cin >> data2.bookNo >> data2.units_sold >> price2;

  data1.revenue = data1.units_sold * price1;
  data2.revenue = data2.units_sold * price2;

  if (data1.bookNo == data2.bookNo) {
    Sales_data sum;
    sum.bookNo = data1.bookNo;
    sum.units_sold = data1.units_sold + data2.units_sold;
    sum.revenue = data1.revenue + data2.revenue;

    cout << sum.bookNo << " " << sum.units_sold << " " << sum.revenue << " "
         << sum.revenue / sum.units_sold << endl;
    return 0;
  } else {
    cerr << "Books must have the same ISBN" << endl;
    return -1;
  }

  return 0;
}