#include <iostream>
using std::cout;
using std::endl;

int main() {
  auto f = [](int i, int j) -> int { return i + j; };
  cout << f(3, 4) << endl;
  return 0;
}