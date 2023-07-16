#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  deque<string> d;

  while (cin >> s) {
    d.push_back(s);
  }

  for (auto ix = d.cbegin(); ix != d.cend(); ++ix) {
    cout << *ix;
    if (ix != d.cend() - 1) {
      cout << ", ";
    } else {
      cout << endl;
    }
  }
  return 0;
}