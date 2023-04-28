#include <iostream>

int main() {
  if (p = getPtr() != 0) {
    // No paranthesis and since assignment has low priority
    // p is assigned to (getPtr() != 0) so it is a bool
    // Correct is (p=getPtr()) != 0
  }
  if (i = 1024) {
    // Should be i == 1024, otherwise will evaluate as true
    // since i is assigned to 1024 which is nonzero
  }
}