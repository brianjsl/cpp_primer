#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace std::placeholders;

vector<int>::const_iterator find_longer(vector<int> &vec, int l) {
  for (auto idx = vec.cbegin(); idx != vec.cend(); ++idx) {
    if (*idx > l) {
      return idx;
    }
  }
  return vec.cend();
}

int main() {
  vector<int> vec = {1, 8, 11, 13, 15, 5, 9};
  string s = "hello world";
  auto b = bind(find_longer, _1, s.size());
  cout << *b(vec) << endl;
  return 0;
}