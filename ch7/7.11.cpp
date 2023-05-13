// See 7.6.cpp
#include "Sales_data_class.h"
#include <iostream>
using namespace std;

int main() {
  Sales_data book1 = Sales_data();
  Sales_data book2 = Sales_data("812-301-201X");
  Sales_data book3 = Sales_data("812-301-201Y", 32, 13.99);
  Sales_data book4 = Sales_data(cin);

  Sales_data books[4] = {book1, book2, book3, book4};

  for (const auto book : books) {
    print(cout, book);
    cout << endl;
  }
  return 0;
}