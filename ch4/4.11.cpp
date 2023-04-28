#include <iostream>
using namespace std;

int main() {
  int a = 3, b = 2, c = 1, d = -1;
  if (a > b && b > c && c > d) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }
  return 0;
}
