#include "Sales_data.hpp"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  Sales_data total;
  double price;

  ifstream input(argv[1]);
  ofstream output(argv[2]);

  if (read(input, total)) {
    Sales_data trans;
    while (read(input, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(output, total);
        output << "\n";
        total = trans;
      }
    }
    print(output, total);
    output << "\n";
  } else {
    cerr << "No data?!" << endl;
    return -1;
  }
  return 0;
}