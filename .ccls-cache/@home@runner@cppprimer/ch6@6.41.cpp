#include <iostream>
using namespace std;

char *init(int ht, int wd = 80, char bckgrnd = ' ');

int main() {
  // Illegal, ht not initialized
  init();

  // Legal:
  init(24, 10);

  // Legal, but unlikely to match intent.
  // Equivalent to init(14, 42, ' '), since
  // the '*' is typecast to an int, namely 42
  init(14, '*');
}