#include <iostream>

int main() {
  int a = 3, b = 4;
  decltype(a) c = a;   // c is a int
  decltype((b)) d = a; // d is a &int referencing a
  ++c;                 // c = 4
  ++d;                 // d = a = 4
  // a,b,c,d = 4
  std::cout << a << " " << b << " " << c << " " << d << std::endl;
  return 0;
}