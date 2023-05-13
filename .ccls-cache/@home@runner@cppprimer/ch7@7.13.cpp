#include "Sales_data_class.h"
#include <iostream>
using namespace std;

int main() {
  Sales_data total(cin);
  double price;

  if (cin) {
    Sales_data trans(cin);
    while (cin) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(cout, total);
        cout << endl;
        total = trans;
      }
      read(cin, trans);
    }
    print(cout, total);
    cout << endl;
  } else {
    cerr << "No data?!" << endl;
    return -1;
  }
  return 0;
}