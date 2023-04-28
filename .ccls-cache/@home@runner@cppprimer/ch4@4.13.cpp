#include <iostream>
using namespace std;

int main() {
  int i;
  double d;
  d = i = 3.5; // i is 3 and d is 3.0
  cout << d << " " << i << endl;
  i = d = 3.5; // d is 3.5 and i is 3
  cout << d << " " << i << endl;
  return 0;
}