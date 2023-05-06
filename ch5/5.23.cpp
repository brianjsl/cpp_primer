#include <exception>
#include <iostream>
using namespace std;

int main() {
  int i1, i2;
  cout << "Enter two numbers: ";
  cin >> i1 >> i2;
  cout << i1 << " / " << i2 << " = " << static_cast<double>(i1) / i2 << endl;
  return 0;
}