#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {1, 3, 2, 8, 9, 3, 2, 8, 7};
  for (auto &i : v) {
    (i % 2 == 0) ? (i *= 2) : true;
  }
  for (const auto c : v) {
    cout << c << " ";
  }
  cout << endl;
  return 0;
}