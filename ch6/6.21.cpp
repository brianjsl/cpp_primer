#include <iostream>
using namespace std;

int larger(int val1, const int *val2) {
  if (val1 >= *val2) {
    return val1;
  } else {
    return *val2;
  }
}

int main() {
  int i = 32, j = 42;
  int *k = &j;
  cout << larger(i, k) << endl;
  return 0;
}