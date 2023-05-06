#include <iostream>
using namespace std;

int abs(int val) {
  if (val <= 0) {
    return -val;
  }
  return val;
}

int main() {
  cout << abs(5) << endl;
  cout << abs(-5) << endl;
  return 0;
}