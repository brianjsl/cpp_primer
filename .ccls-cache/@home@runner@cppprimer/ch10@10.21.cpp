#include <iostream>
using namespace std;

int main() {
  int i = 6;
  auto f = [i]() mutable {
    if (i > 0)
      --i;
    return i == 0;
  };
  for (int i = 0; i < 6; ++i) {
    f();
  }
  if (f()) {
    cout << "i is " << 0 << endl;
  };
}