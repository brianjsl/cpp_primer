#include <iostream>
using namespace std;

int get_value() { return 3; }

int main() {
  int ival1 = 4, ival2 = 3;
  int ival = 2, minval = 3;
  bool occurs;
  if (ival1 != ival2)
    ival1 = ival2;
  else
    ival1 = ival2 = 0;

  if (ival < minval) {
    minval = ival;
    occurs = 1;
  }

  if (int ival = get_value())
    cout << "ival = " << ival << endl;
  else if (!ival) {
    cout << "ival = 0\n" << endl;
  }

  if (ival == 0)
    ival = get_value();

  return 0;
}