#include <iostream>

int main() {
  // Should print 10 10
  int i, &ri = i;
  i = 5;
  ri = 10;
  std::cout << i << " " << ri << std::endl;
  return 0;
}