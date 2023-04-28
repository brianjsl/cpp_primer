#include <iostream>
using namespace std;

int main() {
  int i = 3;
  double d = 2.7;
  i *= static_cast<int>(d);
  cout << i << endl;
  return 0;
}