#include <iostream>
using namespace std;

int main() {
  unsigned long ull = 3;        // 00000011
  unsigned long ul2 = 7;        // 00000111
  cout << (ull & ul2) << endl;  // 00000011 = 3
  cout << (ull | ul2) << endl;  // 00000111 = 7
  cout << (ull && ul2) << endl; // 1 Since both are nonzero
  cout << (ull || ul2) << endl; // 1 Since both are nonzero
  return 0;
}