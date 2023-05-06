#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec1 = {1, 4, 2, 5, 3};
  vector<int> vec2 = {1, 4, 2, 5, 3, 8};
  bool is_prefix = true;

  if (vec1.size() < vec2.size()) {
    auto val = vec2.begin();
    for (auto c : vec1) {
      if (c != *val) {
        is_prefix = false;
        break;
      }
    }
  }
  switch (is_prefix) {
  case true:
    cout << "Is Prefix" << endl;
    break;
  case false:
    cout << "Is not prefix" << endl;
    break;
  }
  return 0;
}