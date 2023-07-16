#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "hello what in the wrld is going on with this wrld";
  string oldVal = "wrld";
  string newVal = "world";
  for (auto iter = s.begin(); iter != s.end(); ++iter) {
    auto size_left = s.end() - iter;
    if (size_left >= oldVal.length()) {
      string subs(iter, iter + oldVal.length());
      if (subs == oldVal) {
        iter = s.erase(iter, iter + oldVal.length());
        iter = s.insert(iter, newVal.begin(), newVal.end());
      }
    }
  }
  cout << s << endl;
  return 0;
}