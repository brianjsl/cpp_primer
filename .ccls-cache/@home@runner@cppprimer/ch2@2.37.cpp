#include <iostream>

int main() {
  int a = 3, b = 4;
  decltype(a) c = a;     // c is an int; c = 3
  decltype(a = b) d = a; // d is an int&;
  d++;                   // d = a = 4
  std::cout << a << " " << b << " " << c << " " << d << std::endl;
  return 0;
}