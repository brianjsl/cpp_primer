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

void get_fact() {
  int input;
  cout << "Enter a number: ";
  cin >> input;
  cout << input << "! = " << fact(input) << endl;
}

int main() {
  get_fact();
  return 0;
}