#include <iostream>
using namespace std;

int main() {
  int sz = 3;
  // ix not defined outside of scope
  // can be corrected by writing outside of for loop
  int ix = 0;
  for (; ix != sz; ++ix) { /* */
  }
  if (ix != sz)
    // ...;

    int ix;
  // forgot semicolon
  for (; ix != sz; ++ix) { /* */
  }

  // Technically legal, but will not terminate unless
  // sz is somehow changed iun body
  for (int ix = 0; ix != sz; ++ix, ++sz) {
    /* */
  }
}