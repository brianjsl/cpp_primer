#include <iostream>
using namespace std;

int main() {
  int val;
  cin >> val;
  if (val % 2 == 0) {
    cout << "Even" << endl;
  } else {
    cout << "Odd" << endl;
  }
  return 0;
}