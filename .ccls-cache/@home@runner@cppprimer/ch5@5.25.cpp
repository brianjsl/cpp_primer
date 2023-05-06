#include <exception>
#include <iostream>
using namespace std;

int main() {
  int i1, i2;
  cout << "Enter two numbers: ";
  cin >> i1 >> i2;

  while (cin) {
    try {
      if (i2 == 0)
        throw runtime_error("Dividend cant be 0!");
      cout << i1 << " / " << i2 << " = " << static_cast<double>(i1) / i2
           << endl;
      break;
    } catch (runtime_error err) {
      cout << err.what() << endl;
      cout << "Enter two numbers: ";
      cin >> i1 >> i2;
    }
  }
  return 0;
}