#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  int i;
  while (cin >> i) {
    v.push_back(i);
  }
  for (auto i = v.cbegin(); v.cbegin() != v.cend() && i != v.cend() - 1; ++i) {
    cout << *i + *(i + 1) << " ";
  }
  cout << endl;

  auto mid = v.cbegin() + v.size() / 2;
  for (auto i = v.cbegin(), j = v.cend() - 1; i != mid; ++i, --j) {
    cout << *i + *j << " ";
  }
  cout << endl;
  return 0;
}