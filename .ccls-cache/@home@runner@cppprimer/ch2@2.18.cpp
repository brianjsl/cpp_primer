#include <iostream>

int main() {
  int i = 32, *j = 0;
  j = &i;
  std::cout << "j = " << *j << std::endl;
  return 0;
}