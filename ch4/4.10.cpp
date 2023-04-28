#include <iostream>
using namespace std;

int main() {
  int val;
  cout << "Enter a number: ";
  while (cin >> val && val != 42) {
    cout << "Enter a number: ";
  }
  cout << endl;
  return 0;
}