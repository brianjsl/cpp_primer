#include <iostream>
using namespace std;

int sum(initializer_list<int> il) {
  int sum = 0;
  for (auto i : il) {
    sum += i;
  }
  return sum;
}

int main() {
  cout << sum({3, 4, 6, 5, 2}) << endl;
  return 0;
}