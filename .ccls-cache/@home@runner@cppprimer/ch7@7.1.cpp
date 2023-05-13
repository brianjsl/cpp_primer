#include "Sales_data.h"
#include <iostream>
using namespace std;

int main() {
  Sales_data total;
  double price;

  if (cin >> total.bookNo >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    Sales_data trans;
    while (cin >> trans.bookNo >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;
      if (total.bookNo == trans.bookNo) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        cout << total.bookNo << " " << total.units_sold << " " << price << endl;
        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue;
      }
    }
    cout << total.bookNo << " " << total.units_sold << " " << price << endl;
  } else {
    cerr << "No data?!" << endl;
    return -1;
  }
  return 0;
}
