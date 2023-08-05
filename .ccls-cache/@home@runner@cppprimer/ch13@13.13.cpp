#include <iostream>

struct X {
  X() { std::cout << "X()" << std::endl; };
  X(const X &) { std::cout << "X(const X&)" << std::endl; };
  X &operator=(const X &) {
    std::cout << "X operator=(const X&)" << std::endl;
    return *this;
  };
  ~X() { std::cout << "~X()" << std::endl; }
};

int main() {
  X x1, x2, &x3 = x1; // copy constructor for x1 and x2
  x1 = x2;            // copy-assignment constructor for x1
  X *x4 = new X; // dynamically allocates space for X and calls copy constructor
  *x4 = x2;      // copy-assignment
  delete x4;     // destructor
  return 0;
} // implicit destruction of x1 and x2 (x3 is a reference so doesn't need to be
  // destroyed)