#include <iostream>
using namespace std;

int fact(int val) {
  try {
    if (val < 0)
      throw runtime_error("Value must be nonnegative!");
    else if (val == 0 || val == 1)
      return 1;
    return val * fact(val - 1);
  } catch (runtime_error err) {
    cout << err.what() << endl;
    return -1;
  }
}

int main() {
  cout << fact(5) << endl;
  return 0;
}