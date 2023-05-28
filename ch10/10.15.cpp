#include <iostream>
using std::cout;
using std::endl;

int main() {
  int i = 3;
  auto f = [i](int j) -> int { return i + j; };
  cout << f(4) << endl;
  return 0;
}