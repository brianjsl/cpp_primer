#include <deque>
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
  string s;
  list<string> l;

  while (cin >> s) {
    l.push_back(s);
  }

  for (auto ix = l.cbegin(); ix != l.cend(); ++ix) {
    cout << *ix;
    if (next(ix) != l.cend()) {
      cout << ", ";
    } else {
      cout << endl;
    }
  }
  return 0;
}