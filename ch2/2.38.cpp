#include <iostream>

int main() {
  int a = 3, &b = a; // a=b=3
  auto c = b;        // c is an int, c = 3
  decltype(b) d = a; // d is a int&, d = a
  d++;               // a = b = d = 4
  std::cout << a << " " << b << " " << c << " " << d << std::endl;
  return 0;
}