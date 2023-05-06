#include <iostream>
using namespace std;

// Error since the function prototype is equivalent to const *int so we can
// pass in arrays of more than 10 values. What we need is a reference type.
void print(const int (&ia)[10]) {
  for (auto beg = begin(ia); beg != end(ia); ++beg) {
    cout << *beg << endl;
  }
}

int main() {
  int j[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(j);
  cout << endl;
  return 0;
}