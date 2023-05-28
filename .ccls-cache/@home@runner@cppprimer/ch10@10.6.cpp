#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &vec) {
  for (const auto &v : vec) {
    cout << v << " ";
  }
  cout << endl;
}
int main() {
  vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  fill_n(vec.begin(), vec.size(), 0);
  print(vec);
  return 0;
}