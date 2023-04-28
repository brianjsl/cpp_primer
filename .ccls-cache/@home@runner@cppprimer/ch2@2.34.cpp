#include <iostream>

int main() {
  int i = 0, &r = i;
  auto a = r;

  const int ci = i, &cr = ci;
  auto b = ci;
  auto c = cr;
  auto d = &i;
  auto e = &ci;

  auto &g = ci;

  a = 42; // legal since a is an int
  b = 42; // legal since b is an int
  c = 42; // legal since c is an int

  // std::cout << a << " " << b << " " << c << std::endl;
  d = 42; // d is an int*, so you cannot assign a literal (need to assign an
          // address)
  e = 42; // e is an const int*, so cannot assign a literal
  g = 42; // g is a const int& so you cannot assign anything to it after
          // initialization.

  return 0;
}