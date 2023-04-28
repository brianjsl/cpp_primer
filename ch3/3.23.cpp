#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {1, 4, 32, 5, 8, 10, 2, 7, 9, 7};
  for (auto i = v.begin(); i != v.end(); ++i) {
    *i = 2 * (*i);
  }
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}